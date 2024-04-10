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
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e6 + 10; 
const long long INF = 1e9 + 19;
typedef long long ll;

int n;
pair<ll, ll> b[N];
ll T;

void read() {
    scanf("%d", &n);
    ll w;
    scanf("%lld%lld", &T, &w);
    n--;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &b[i].fr, &b[i].sc);
    }
}

void solve() {
    sort(b, b + n, greater<pair<ll,ll>>());
    multiset<ll> q;
    int answer = INF;
    int rem = 0;
    int cur = 0;
    //for (int i = 0; i < n; i++)
        //cerr << b[i].fr << " " << b[i].sc << endl;
    for (;;) {
        //db(T);
        for (; cur < n && b[cur].fr > T; cur++) {
            q.insert(b[cur].sc - b[cur].fr + 1);
        }
        //db3(answer, cur, rem);
        answer = min(answer, cur - rem);
        if (q.empty())
            break;
        ll x = *q.begin(); 
        //db2(T, x);
        if (T >= x) {
            T -= x;
            rem++;
            q.erase(q.begin());
        }
        else
            break;
    }
    cout << answer + 1 << endl;



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