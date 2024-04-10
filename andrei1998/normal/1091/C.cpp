#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main()
{
    int N;
    cin >> N;

    vector <int> divs;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            divs.push_back(i);
            if (i != N / i)
                divs.push_back(N / i);
        }
    }

    vector <lint> sol;
    for (auto d: divs) {
        sol.push_back(N / d * (N - d + 2LL) / 2);
    }

    sort(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    }
    return 0;
}