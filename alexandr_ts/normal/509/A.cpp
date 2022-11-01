#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

long long a[100][100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i][1] = a[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            a[i][j] = a[i][j - 1] + a[i - 1][j];
    cout << a[n][n];
}