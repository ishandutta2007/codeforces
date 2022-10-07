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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

int nx(int i, int n) { return (i == n - 1)? 0: i + 1; }
int pr(int i, int n) { return (i == 0)? n - 1: i - 1; }

typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;

int answer;
vector<pair<int,int>> f;
int a, b;

void rec(int pos, ll h, ll w, int done) {
    if (h >= a && w >= b) {
        answer = min(answer, done);
        return;
    }
    if (pos == sz(f)) return;

    for (int x = 0; x <= f[pos].S; x++) {
        ll curW = w;
        for (int y = 0; x + y <= f[pos].S; y++) {
            if (h >= a && curW >= b) {
                answer = min(answer, done + x + y);
                break;
            }
            if (x + y == f[pos].S) {
                rec(pos + 1, h, curW, done + f[pos].S);
            }
            if (curW >= b) break;
            curW *= f[pos].F;
        }

        if (h >= a) break;
        h *= f[pos].F;
    }
    


}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif

    int h, w, n;
    scanf("%d%d%d%d %d", &a, &b, &h, &w, &n);
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    sort(all(c));
    reverse(all(c));

    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && c[i] == c[j]; i++);
        f.pb({c[j], i - j});
    }

    answer = INF;

    for (int tt = 0; tt < 2; tt++) {
        rec(0, h, w, 0);

        swap(a, b);
    }

    if (answer == INF)
        answer = -1;

    cout << answer << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}