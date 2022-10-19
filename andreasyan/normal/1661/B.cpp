#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 32768;

vector<int> g[N];

int d[N];
bool c[N];

void solv()
{
    for (int i = 0; i < N; ++i)
    {
        g[(i + 1) % N].push_back(i);
        g[(i * 2) % N].push_back(i);
    }

    queue<int> q;
    q.push(0);
    d[0] = 0;
    c[0] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
            {
                q.push(h);
                d[h] = d[x] + 1;
                c[h] = true;
            }
        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x;
        cin >> x;
        cout << d[x] << ' ';
    }
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}