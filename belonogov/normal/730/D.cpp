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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define equal equalll
#define less lesss
typedef long long ll;
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n;
ll r;
int l[N];
int t[N];
int need[N];


void read() {
    scanf("%d%I64d", &n, &r);
    for (int i = 0; i < n; i++)
        scanf("%d", &l[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (l[i] > t[i]) {
            puts("-1");
            return;
        }
        need[i] = max(0, l[i] * 2 - t[i]);
    }
    ll answer = 0;
    vector<pair<ll, int>> b; 
    ll prev = 0;
    ll curT = 0;

    //for (int i = 0; i < n; i++)
        //cerr << need[i] << " ";
    //cerr << endl;

    for (int i = 0; i < n; i++) {
        ll sumPower = min(prev, l[i] * 1ll);
        prev -= sumPower;
        if (need[i] > sumPower) {
            ll rem = need[i] - sumPower;
            ll cnt = (rem + r - 1) / r;
            answer += cnt;

            sumPower += rem;
            ll tEnd = curT + sumPower + (l[i] - sumPower) * 2;

            b.pb(mp(tEnd - rem, cnt));

            assert(cnt * r >= rem);
            prev = (cnt * r) - rem;
        }

        curT += sumPower + (l[i] - sumPower) * 2;
    }

    cout << answer << endl;
    if (answer <= 1e5) {
        for (auto x: b) {
            for (int i = 0; i < x.sc; i++)
                printf("%I64d ", x.fr + i * r);
        }
        puts("");
    }





}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}