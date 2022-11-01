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
        int n,m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<bool> p(n,0);
        while(m--)
        {
            int x;
            cin >> x;
            p[x-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(p[i]==0) continue;
            int x=i;
            while(x<n&&p[x]==1) x++;
            sort(v.begin()+i,v.begin()+x+(x<n));
            i=x;
        }
        bool ok=1;
        for(int i=0;i<n-1;i++) ok&=(v[i]<=v[i+1]);
        if(ok==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}