#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 305;

int A[Nmax];

vector< pair<int, int> > Tubes[Nmax * Nmax];

int N, M, K;

pair<int, int> next_pos(pair<int, int> pos)
{
    if (pos.first % 2 == 1)
    {
        if (pos.second == M)
            pos.first++;
        else
            pos.second++;
    }
    else
    {
        if (pos.second == 1)
            pos.first++;
        else
            pos.second--;
    }

    return pos;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    cin >> N >> M >> K;

    pair<int, int> pos;
    int NrTubes = 1, step = 0;

    for (pos = make_pair(1, 1); NrTubes < K; pos = next_pos(pos))
    {
        Tubes[NrTubes].push_back(pos);

        step++;
        if (step == 2) step = 0;

        if (!step)
            ++NrTubes;
    }

    for (; pos.first <= N; pos = next_pos(pos))
    {
        Tubes[K].push_back(pos);
    }

    for (int i = 1; i <= K; i++)
    {
        cout << Tubes[i].size () << " ";

        for (auto p: Tubes[i])
            cout << p.first << " " << p.second << " ";

        cout << "\n";
    }
}