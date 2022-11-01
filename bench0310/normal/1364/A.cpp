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
        int n,x;
        cin >> n >> x;
        vector<int> v(n);
        int m=n;
        for(int i=0;i<n;i++)
        {
            cin >> v[i];
            if(i>0) v[i]+=v[i-1];
            v[i]%=x;
            if(v[i]>0) m=min(m,i);
        }
        int res=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0) res=max(res,i-m);
            else res=max(res,i+1);
        }
        cout << res << "\n";
    }
    return 0;
}