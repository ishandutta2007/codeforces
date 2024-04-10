#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string Names[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    string S;

    cin >> N >> S;

    for (int i = 0; ; i++)
    {
        if (Names[i].size() != S.size()) continue;

        bool ok = 1;
        for (int j = 0; j < N; j++)
            if (S[j] != '.' && S[j] != Names[i][j])
                ok = 0;

        if (ok)
        {
            cout << Names[i] << '\n';
            return 0;
        }
    }
}