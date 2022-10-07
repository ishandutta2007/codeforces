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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;

int n;
pair<int,int> a[N];
pair<int,int> b[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d", &a[i].fr, &a[i].sc, &b[i].fr, &b[i].sc);
}

void solve() {
    ll answer = 0;
    vector<pair<int,int>> c;
    ll bal = 0;
    ll part2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].fr + a[i].sc >= b[i].fr + b[i].sc) {
            c.pb(mp(a[i].fr + a[i].sc, b[i].fr + b[i].sc));
            bal += a[i].fr + b[i].fr;
            bal -= a[i].sc + b[i].sc; 
        }
        else {
            if (a[i].fr - b[i].sc > 0) 
                part2 += a[i].fr - b[i].sc; 
            if (a[i].sc - b[i].fr > 0)
                part2 -= a[i].sc - b[i].fr;
        }
    } 
    
    multiset<pair<ll, ll>> q;
    for (auto x: c)
        q.insert(mp(x.fr, x.sc));

    int iter = 0;
    for (;!q.empty(); iter++) {
        auto pr = *q.rbegin();
        q.erase(q.find(pr));
        if (iter % 2 == 0) {
            answer += pr.fr; 
        }
        else {
            answer -= pr.fr;
        }
        if (pr.sc != -1) {
            q.insert(mp(pr.sc, -1));
        }
    }
    assert((answer + bal) % 2 == 0);
    cout << part2 + (answer + bal) / 2 << endl;
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