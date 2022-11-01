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
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        bool x=0;
        for(int s=0;s<m;s++)
        {
            vector<vector<bool>> v(n,vector<bool>(m,0));
            int now=0;
            for(int o=0;o<n;o++)
            {
                int cnt=a;
                for(int i=now;cnt>0;i=(i+1)%m)
                {
                    v[o][i]=1;
                    cnt--;
                }
                now=(now+s)%m;
            }
            bool ok=1;
            for(int o=0;o<n;o++)
            {
                int cnt=0;
                for(int i=0;i<m;i++) cnt+=v[o][i];
                ok&=(cnt==a);
            }
            for(int i=0;i<m;i++)
            {
                int cnt=0;
                for(int o=0;o<n;o++) cnt+=v[o][i];
                ok&=(cnt==b);
            }
            if(ok)
            {
                cout << "YES\n";
                for(int o=0;o<n;o++)
                {
                    for(int i=0;i<m;i++) cout << v[o][i];
                    cout << "\n";
                }
                x=1;
                break;
            }
        }
        if(x==0) cout << "NO\n";
    }
    return 0;
}