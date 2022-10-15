#include<bits/stdc++.h>

using namespace std;

const int MaxN = 3e5 + 15;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

vector <int> v[MaxN];

int n, m;

int d[MaxN];
int p[MaxN];

void dj(int x)
{
    int ss = x;

    for(int i = 1; i <= n; ++i)
        d[i] = MOD;

    d[x] = 0;

    set<pair<int, int> > s;

    s.insert(make_pair(0, x));

    while(!s.empty())
    {
        int x = (*s.begin()).second;
        s.erase(s.begin());
        for(int to : v[x])
        {
            if(ss != 1 && to == 1)
                continue;
            if(d[to] > d[x] + 1)
            {
                s.erase({d[to], to});
                d[to] = d[x] + 1;
                p[to] = x;
                s.insert({d[to], to});
            }
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        if(x > y)
            swap(x, y);

        if(x == 1 && y == n)
        {
            cout << "1\n";
            cout << 1 << ' ' << n << '\n';
            return 0;
        }

        v[x].push_back(y);
        v[y].push_back(x);
    }

    dj(1);

    if(d[n] == 2)
    {
        cout << 2 << '\n';
        cout << 1 << ' ' << p[n] << ' ' << n << '\n';
        return 0;
    }

    if(d[n] == 3)
    {
        cout << 3 << '\n';
        cout << 1 << ' ' << p[p[n]] << ' ' << p[n] << ' ' << n << '\n';
        return 0;
    }

    if(d[n] == 4)
    {
        cout << 4 << '\n';
        cout << 1 << ' ' << p[p[p[n]]] << ' ' << p[p[n]] << ' ' << p[n] << ' ' << n << '\n';
        return 0;
    }

    for(int i = 2; i < n; ++i)
        if(d[i] == 2)
        {
            cout << 4 << '\n';
            cout << 1 << ' ' << p[i] << ' ' << i << ' ' << 1 << ' ' << n << '\n';
            return 0;
        }

    if(d[n] == 5)
    {
        cout << 5 << '\n';
        cout << 1 << ' ' << p[p[p[p[n]]]] << ' ' << p[p[p[n]]] << ' ' << p[p[n]] << ' ' << p[n] << ' ' << n << '\n';
        return 0;
    }

    vector <int> c = v[1];

    for(int i = 0; i < c.size(); ++i)
    {
        int x = c[i];
        dj(x);
        for(int j = 0; j < c.size(); ++j)
            if(d[c[j]] == 2)
            {
                int y = c[j];
                cout << 5 << '\n';
                cout << 1 << ' ' << x << ' '  << p[y] << ' ' << y << ' ' << x << ' ' << n << '\n';
                return 0;
            }
    }

    cout << -1 << '\n';

    return 0;
}

///7