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
        for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> v[o][i];
        int a=0,b=0;
        for(int o=0;o<n;o++)
        {
            bool ok=1;
            for(int i=0;i<m;i++) ok&=(v[o][i]==0);
            a+=ok;
        }
        for(int i=0;i<m;i++)
        {
            bool ok=1;
            for(int o=0;o<n;o++) ok&=(v[o][i]==0);
            b+=ok;
        }
        if(min(a,b)&1) cout << "Ashish\n";
        else cout << "Vivek\n";
    }
    return 0;
}