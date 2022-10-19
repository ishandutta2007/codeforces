#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 1000007;
int N, K, phi[MAXN], prime[MAXN];

int main()
{
    cin >> N >> K;
    if (K == 1) return cout << 3 << endl, 0;
    for (int i = 2; i <= N; ++i) phi[i] = i;
    for (int i = 2; i <= N; ++i) if (!prime[i]) {
        for (int j = i; j <= N; j += i) {
            prime[j] = i;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    sort(phi + 3, phi + N + 1);
    cout << accumulate(phi + 3, phi + K + 3, 2ll) << endl;
}