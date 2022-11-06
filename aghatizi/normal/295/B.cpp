#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 500 + 20;
const ll inf = 1e18;

ll d[maxn][maxn];

int x[maxn];

bool visited[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> d[i][j];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        x[i]--;
    }

    vector<ll> ans;
    for(int k = n - 1; k >= 0; k--)
    {
        visited[x[k]] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][x[k]] + d[x[k]][j]);

        ll res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(visited[i] && visited[j])
                    res += d[i][j];
            }

        ans.push_back(res);
    }

    reverse(ans.begin(), ans.end());

    for(auto res : ans)
        cout << res << " ";
    cout << endl;
}