#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define sz(x) ((int)x.size())
#define endl "\n"
#define inf (1LL<<62)
#define ninf (-inf)

int b[200005];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        for(int i = 1; i <= m; i++)
            cin >> b[i];
        if((n-m)%(k-1) != 0)
            cout << "NO\n";
        else
        {
            vector<int> v;
            int pos = 1;
            for(int i = 1; i <= n; i++)
            {
                if(pos <= m && b[pos] == i)
                    pos++;
                else
                    v.pb(i);
            }
            int moves = (n-m)/(k-1), flag = 0;
            for(int i = 1; i <= m; i++)
            {
                int pos2 = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
                int l = pos2, r = (n-m)-pos2;
                if(l >= (k/2) && r >= (k/2))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}