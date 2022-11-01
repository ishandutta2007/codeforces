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
        vector<vector<int>> v(n,vector<int>(m,0));
        v[0][0]=v[n-1][0]=v[0][m-1]=v[n-1][m-1]=2;
        for(int i=1;i<m-1;i++) v[0][i]=v[n-1][i]=3;
        for(int o=1;o<n-1;o++) v[o][0]=v[o][m-1]=3;
        for(int o=1;o<n-1;o++) for(int i=1;i<m-1;i++) v[o][i]=4;
        bool ok=1;
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                int a;
                cin >> a;
                ok&=(a<=v[o][i]);
            }
        }
        if(ok==1)
        {
            cout << "YES\n";
            for(int o=0;o<n;o++) for(int i=0;i<m;i++) cout << v[o][i] << " \n"[i==m-1];
        }
        else cout << "NO\n";
    }
    return 0;
}