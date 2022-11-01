#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

char a[10][10];

int main() {
    //freopen("input.txt", "r", stdin);
    fr(i, 4)
        fr(j, 4)
            cin >> a[i][j];
    fr(i, 3)
        fr(j, 3) {
            int q1 = 0, q2 = 0;
            if (a[i][j] == '.') q1++; else q2++;
            if (a[i + 1][j] == '.') q1++; else q2++;
            if (a[i][j + 1] == '.') q1++; else q2++;
            if (a[i + 1][j + 1] == '.') q1++; else q2++;
            if (q1 != q2) {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
}