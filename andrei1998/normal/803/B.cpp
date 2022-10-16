#include <iostream>

using namespace std;

int N;
const int NMAX = 2E5 + 5;

int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> v[i];
        if (v[i] != 0)
            v[i] = NMAX + 5;
    }

    for (int i = 2; i <= N; ++ i)
        v[i] = min(v[i], v[i - 1] + 1);
    for (int i = N - 1; i; -- i)
        v[i] = min(v[i], v[i + 1] + 1);

    for (int i = 1; i <= N; ++ i)
        cout << v[i] << " \n"[i == N];
    return 0;
}