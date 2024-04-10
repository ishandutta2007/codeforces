#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 1;
const ld EPS = 1e-8;

char a[N][N];
int n;

void check(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        cout << "NO";
        exit(0);
    }
    a[i][j] = '.';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    fr(i, n)
        fr(j, n)
            cin >> a[i][j];
    int cnt = 0;
    fr(i, n)
        fr(j, n)
            cnt += (a[i][j] == '#');
    fr(i1, n * n / 5 + 1) {
        bool fnd = false;
        fr(i, n) if (!fnd)
            fr(j, n)
                if (!fnd && a[i][j] == '#') {
                    check(i + 1, j);
                    check(i + 1, j - 1);
                    check(i + 1, j + 1);
                    check(i + 2, j);
                    check(i, j);
                    cnt -= 5;
                }
    }
    if (cnt != 0) {
        cout << "NO";
    }
    else cout << "YES";
}