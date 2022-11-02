#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, x, q;
char c[33][33];
string s;
vector<pii> A;
int calc(char C) {
    int a = 0, b = 0;
    char d = tolower(C);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == d) {
                if(c[i][j] == C) {
                    a = 1;
                    b = 1;
                } else {
                    if(A.size() > 0) b = 1;
                    for(auto h: A) {
                        int e = h.first - i;
                        int f = h.second - j;
                        if(e * e + f * f <= x * x) {
                            a = 1;
                        }
                    }
                }
            }
        }
    }
    if(b == 0) return -1;
    if(a == 0) return 1;
    return 0;
}
void solve() {
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) cin >> c[i];
    cin >> q >> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == 'S') {
                A.emplace_back(make_pair(i, j));
            }
        }
    }
    int cnt = 0;
    map<char, int> cost;
    for(int z = 0; z < s.size(); z++) {
        if(cost.count(s[z]) > 0) {

        } else {
            cost[s[z]] = calc(s[z]);
        }
        if(cost[s[z]] == -1) {
            cout << -1 << "\n";
            return;
        }
        cnt += cost[s[z]];
    }
    cout << cnt << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}