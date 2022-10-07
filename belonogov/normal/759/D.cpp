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
#define prev prevv
const int N = 5555;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

int n;
char a[N];
int prev[N];
int f[N];
int dp1[N];
int dp2[N];
int pref[N];

void read() {
    scanf("%d", &n);
    scanf("%s", a);
}

int get(int l, int r) {
    return (pref[r] - pref[l] + MOD) % MOD;
}

void solve() {
    int cur = 0;
    for (int i = 0; i < n; i++)
        if (cur == 0 || a[i] != a[cur - 1]) {
            a[cur++] = a[i];
        }
    memset(prev, -1, sizeof(prev));
    for (int i = 0; i < n; i++) {
        f[i] = prev[(int)a[i]] + 1;
        prev[(int)a[i]] = i;
    }

    dp1[0] = 1;

    for (int i = 0; i < n; i++) {
        //db(i);
        for (int j = 0; j < cur; j++)
            pref[j + 1] = (pref[j] + dp1[j]) % MOD;
        for (int j = 0; j < cur; j++)
            dp1[j] = get(f[j], j + 1);
    }
    ll answer = 0; 
    for (int i = 0; i < cur; i++)
        answer = (answer + dp1[i]) % MOD;

    cout << answer << endl;

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