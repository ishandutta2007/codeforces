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
const int N = 1e6 + 120;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, k;
int tree[N];


void f(int pos, int val) {
    for (; pos < n; pos |= (pos + 1))
       tree[pos + 1] += val; 
}

int get(int r) {
    int sum = 0;
    for (; r > 0; r &= (r - 1))
        sum += tree[r];
    return sum;
}

int get(int l, int r) {
    return get(r) - get(l);
}

void read() {
    scanf("%d%d", &n, &k);
}

void solve() {
    ll val = 1;
    int v = 0;
    if (k * 2 > n)
        k = n - k;
    for (int i = 0; i < n; i++) {
        int u = v + k;
        ll add = 1;
        if (u >= n) {
            add--;
            if (i == n - 1)
                add++;
            add += 2 * (get(v, n) + get(0, u - n));
        } 
        else {
            add += 2 * get(v, u);
        }

        val += add;
        printf("%lld ", val);
        f(v, 1);
        v = u % n;
    }
    puts("");

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