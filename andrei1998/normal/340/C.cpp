#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lint;

lint gcd(lint a, lint b) {
    if (!b)
        return a;
    lint r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

const int NMAX = 100000 + 5;

int N;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];
    sort(v + 1, v + N + 1);

    lint num = 1LL * N * v[1];
    lint den = N;

    for (int k = 1; k <= N; ++ k)
        num += (N - k) * (2 * k + 1LL) * (v[k + 1] - v[k]);

    lint d = gcd(num, den);
    num /= d;
    den /= d;

    cout << num << ' ' << den << '\n';
    return 0;
}