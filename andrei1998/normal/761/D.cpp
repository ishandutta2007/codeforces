#include <iostream>

using namespace std;

const int NMAX = 100000 + 5;

int a[NMAX];
int c[NMAX];

int p[NMAX];
int where[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int N, L, R;
    cin >> N >> L >> R;

    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    for (int i = 1; i <= N; ++ i) {
        cin >> p[i];
        where[N - p[i] + 1] = i;
    }

    int atMost = a[where[1]] + R;
    for (int i = 1; i <= N; ++ i) {
        int pos = where[i];
        c[pos] = min(atMost, R - a[pos]);
        if (c[pos] < L - a[pos]) {
            cout << "-1\n";
            return 0;
        }
        atMost = c[pos] - 1;
    }

    for (int i = 1; i <= N; ++ i)
        cout << a[i] + c[i] << " \n"[i == N];
    return 0;
}