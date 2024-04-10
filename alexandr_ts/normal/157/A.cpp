#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e2 + 10;
const int INF = 2e9;
const int ALPH = 300;

int a[N][N], b[N][N];



int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        fr(j, n) {
        cin >> a[i][j];
        b[j][i] = a[i][j];
    }
    int ans = 0;
    fr(i, n)
        fr(j, n)
            ans += (accumulate(b[j], b[j] + n, 0) > accumulate(a[i], a[i] + n, 0));
    cout << ans;


}