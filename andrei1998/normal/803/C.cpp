#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lint;

const int NMAX = 200000 + 5;
lint v[NMAX];

int main()
{
    lint N, K;
    cin >> N >> K;

    if (K > 200000) {
        cout << "-1\n";
        return 0;
    }

    lint atLeast = K * (K + 1LL) / 2;
    if (N < atLeast) {
        cout << "-1\n";
        return 0;
    }

    vector <lint> divs;
    for (int i = 1; i <= 200000; ++ i)
        if (N % i == 0) {
            divs.push_back(i);
            if (i != N / i)
                divs.push_back(N / i);
        }

    sort(divs.begin(), divs.end(), greater <lint>());

    lint d = 1;
    for (auto it: divs)
        if (atLeast <= N / it) {
            d = it;
            break;
        }

    N /= d;
    for (int i = 1; i <= K; ++ i) {
        v[i] = i;
        N -= v[i];
    }
    v[K] += N;

    for (int i = 1; i <= K; ++ i)
        cout << v[i] * d << " \n"[i == K];
    return 0;
}