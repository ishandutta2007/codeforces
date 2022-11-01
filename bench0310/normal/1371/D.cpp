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
        vector<vector<int>> v(n,vector<int>(n,0));
        int now=0;
        for(int o=0;o<n;o++)
        {
            int c=k/n+(o<(k%n));
            while(c--)
            {
                v[o][now]=1;
                now=(now+1)%n;
            }
        }
        if((k%n)==0) cout << "0\n";
        else cout << "2\n";
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<n;i++) cout << v[o][i];
            cout << "\n";
        }
    }
    return 0;
}