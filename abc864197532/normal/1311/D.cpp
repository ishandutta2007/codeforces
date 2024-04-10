#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

const int N = 20087;

vector <tuple<int, int, int>> table;

void build() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            for (int k = j; k < N; k += j) {
                table.eb(i, j, k);
            }
        }
    }
}


void solve(int a, int b, int c) {
    int ans = 864197532;
    tuple <int, int, int> aa;
    for (auto A : table) {
        if (ans > abs(get<0>(A) - a) + abs(get<1>(A) - b) + abs(get<2>(A) - c)) {
            ans = abs(get<0>(A) - a) + abs(get<1>(A) - b) + abs(get<2>(A) - c);
            aa = A;
        }
    }
    tie(a, b, c) = aa;
    cout << ans << endl << a << ' ' << b << ' ' << c << endl;
}

int main () {
    int t, a, b, c;
    cin >> t;
    build();
    while (t--) {
        cin >> a >> b >> c;
        solve(a, b, c);
    }
}