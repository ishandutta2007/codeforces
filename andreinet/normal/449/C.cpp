#include <algorithm>
#include <bitset>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005;

bitset<Nmax> Used;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N;
    cin >> N;

    vector< pair<int, int> > Ans;

    vector<int> RemNumers;

    for (int i = 2; i <= N; i <<= 1)
        RemNumers.push_back(i);

    for (int i = 3; i <= N / 2; i++)
    {
        if (!Used[i] && (i & 1))
        {
            vector<int> Numbers;
            for (int j = i; j <= N; j += i)
            {
                if (!Used[j])
                {
                    Used[j] = 1;
                    Numbers.push_back(j);
                }
            }

            if ((Numbers.size() & 1) && Numbers.size() > 1)
            {
                RemNumers.push_back(Numbers[1]);
                Numbers.erase(Numbers.begin() + 1);
            }

            for (int j = 0; j + 1 < int(Numbers.size()); j += 2)
                Ans.push_back(make_pair(Numbers[j], Numbers[j + 1]));
        }
    }

    for (int i = 0; i + 1 < int(RemNumers.size()); i += 2)
        Ans.push_back(make_pair(RemNumers[i], RemNumers[i + 1]));

    cout << Ans.size() << '\n';
    for (const auto p: Ans)
        cout << p.first << ' ' << p.second << '\n';

}