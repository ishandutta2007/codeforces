#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 2000 + 5;

int N;
int a[NMAX];

inline int gcd(int a, int b) {
    return __gcd(a, b);
}

int main()
{
    cin >> N;
    int gc = 0;
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i];
        gc = gcd(gc, a[i]);
    }

    if (gc != 1) {
        cout << "-1\n";
        return 0;
    }
    if (N == 1 && a[1] != 1) {
        cout << "-1\n";
        return 0;
    }

    int shortest = N;
    for (int i = 1; i <= N; ++ i) {
        int gc = 0;
        for (int j = i; j <= N; ++ j) {
            gc = gcd(gc, a[j]);
            if (gc == 1) {
                shortest = min(shortest, j - i + 1);
                break;
            }
        }
    }

    int cnt1 = 0;
    for (int i = 1; i <= N; ++ i)
        if (a[i] == 1)
            ++ cnt1;

    if (cnt1)
        cout << N - cnt1 << '\n';
    else
        cout << shortest - 1 + N - 1 << '\n';
    return 0;
}