#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 505;

int p[N];
int ans[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    f1r(i, 1, n + 1) cin >> p[i];
    auto valid = [&](int x, int y) -> bool { 
        return 1 <= x && x <= n && 1 <= y && y <= n;
    };
    for (int i = n; i >= 1; i--) {  
        ans[i][i] = p[i];
        int num = p[i] - 1;
        int ci = i;
        int cj = i;
        while (num) {
            if (valid(ci + 1, cj) && ans[ci + 1][cj] == 0) {
                ci++;
                ans[ci][cj] = p[i];
            } else {
                cj--;
                ans[ci][cj] = p[i];
            }
            num--;
        }

    }
    f1r(i, 1, n + 1) {
        f1r(j, 1, i + 1) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}