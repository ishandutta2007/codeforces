#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 333;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int n, m, k;
int a[N][N];
int b[N][N];
int c[N][N];

void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int res = 0;
            vector<int> prof;
            for (int t = 0; t < m; t++) {
                if (a[i][t] < b[j][t]) {
                    for (int tt = 0; tt < c[i][t]; tt++)
                        prof.pb(b[j][t] - a[i][t]);
                }
            }
            sort(all(prof));
            reverse(all(prof));
            for (int t = 0; t < (int)prof.size() && t < k; t++)
                res += prof[t];
            answer = max(answer, res);
        }
    }
    cout << answer << endl;
}

void solve() {

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}