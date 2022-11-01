#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> Ans;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int k;
        cin >> k;

        bool ok = 0;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;

            if (x < M)
                ok = 1;
        }

        if (ok) Ans.push_back(i);
    }

    cout << Ans.size() << "\n";

    for (auto p: Ans) cout << p << " ";
    cout << "\n";
}