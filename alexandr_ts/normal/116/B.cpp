#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e2 + 1;

char a[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    int cnt = 0;
    fr(i, n)
        fr(j, m)
            if (a[i][j] == 'W') {
                if (i > 0 && a[i - 1][j] == 'P') cnt++;
                else if (i < n - 1 && a[i + 1][j] == 'P') cnt++;
                else if (j > 0 && a[i][j - 1] == 'P') cnt++;
                else if (j < m - 1 && a[i][j + 1] == 'P') cnt++;
            }
    cout << cnt;

}