#include <algorithm>
#include <bitset>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005;

int Values[Nmax], Nodes[Nmax];
int F[Nmax], Size[Nmax], Poz[Nmax];
vector<int> G[Nmax];

bitset <Nmax> v;

int N;

bool comp(const int &a, const int &b)
{
    return Values[a] > Values[b];
}

int Find(int x)
{
    int y, p;
    for (y = F[x]; y != F[y]; y = F[y]);

    for (; x != y; x = p)
    {
        p = F[x];
        F[x] = y;
    }

    return y;
}

void Unite(int x, int y)
{
    x = Find(x);
    y = Find(y);
    F[x] = y;
    Size[y] += Size[x];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> Values[i], Nodes[i] = i;

    while (M--)
    {
        int x, y;
        cin >> x >> y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    sort(Nodes + 1, Nodes + N + 1, comp);

    for (int i = 1; i <= N; i++)
    {
        F[i] = i;
        Size[i] = 1;
        Poz[Nodes[i]] = i;
    }

    long long Sol = 0;
    for (int i = 1; i <= N; i++)
    {
        const int node = Nodes[i];

        vector <int> vals;
        for (auto p: G[node])
        {
            if (Poz[p] > i) continue;

            int x = Find(node), y = Find(p);

            if (x != y)
            {
                vals.push_back(Size[y]);
                Unite(node, p);
            }
        }

        long long s = 0, s1 = 0;
        for (auto p: vals)
        {
            s1 += 1LL * p * s;
            s += p;
        }
        s1 = s1 * Values[node] + s * Values[node];

        Sol += s1;
    }

    printf("%0.6f\n", (double) Sol * 2 / (1LL * N * (N - 1)));
}