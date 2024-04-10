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
        int n,k;
        cin >> n >> k;
        bool ok=0;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            ok|=(a[i]==k);
        }
        auto median=[&](int l,int r)->int
        {
            vector<int> b;
            for(int i=l;i<=r;i++) b.push_back(a[i]);
            sort(b.begin(),b.end());
            return b[(r-l)/2];
        };
        bool res=0;
        if(n==1) res=(a[1]==k);
        else if(!ok) res=0;
        else
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=2;j<=3&&i+j-1<=n;j++) res|=(median(i,i+j-1)>=k);
            }
        }
        if(res) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}