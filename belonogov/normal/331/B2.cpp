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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, q;
int p[N];
int rev[N];
int tree[N];

void add(int pos, int val) {
    for (; pos <= n; pos |= (pos + 1))
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

void f(int val, int cof) {
    if (0 <= val && val + 1 < n && rev[val] > rev[val + 1])
        add(val, cof);
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++)
        rev[p[i]] = i;

    for (int i = 0; i < n; i++)
        f(i, 1);
    //for (int i = 0; i < n; i++)
        //cerr << get(i, i + 1) << " ";
    //cerr << endl;


    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y); x--; y--;
        if (type == 1) {
            printf("%d\n", get(x, y) + 1);
        }
        else {
            assert(type == 2); 
            vector<int> tmp = {p[x], p[x] - 1, p[y], p[y] - 1};
            sort(all(tmp));
            tmp.resize(unique(all(tmp)) - tmp.begin());
            for (auto w: tmp)
                f(w, -1);
            swap(p[x], p[y]);
            swap(rev[p[x]], rev[p[y]]);

            for (auto w: tmp)
                f(w, 1);
        }
    }
    //for (int i = 0; i < n; i++)
        //cerr << get(i, i + 1) << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << p[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << rev[i] << " ";
    //cerr << endl;

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