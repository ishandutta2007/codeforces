#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        bool eq=0;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) eq|=(a[i]==a[j]);
        vector<int> res;
        auto mv=[&](int i)
        {
            swap(a[i],a[i+1]);
            swap(a[i],a[i+2]);
            res.push_back(i);
        };
        for(int i=n;i>=3;i--)
        {
            int m=0;
            for(int j=1;j<=i;j++) if(a[j]>=a[m]) m=j;
            while(m<i) mv(max(1,(m++)-1));
        }
        bool bad=0;
        if(a[1]==a[2]||a[1]==a[3]||a[2]==a[3])
        {
            while(!(a[1]<=a[2]&&a[2]<=a[3])) mv(1);
        }
        else if(a[1]>a[2]&&eq)
        {
            int x=0;
            for(int i=3;i<=n-1;i++) if(a[i]==a[i+1]) x=i;
            for(int i=2;i<x-1;i++) mv(i-1);
            mv(x-1);
            mv(x-2);
            for(int i=x-2;i>1;i--)
            {
                mv(i-1);
                mv(i-1);
            }
        }
        else if(a[1]>a[2]&&!eq) bad=1;
        if(!bad)
        {
            cout << res.size() << "\n";
            for(int x:res) cout << x << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}