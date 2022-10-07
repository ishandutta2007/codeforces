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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const int T = 3;
const int MOD = 777777777; 

struct Mat {
    int a[T][T];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void Epr() {
        cerr << "Mat:\n";
        for (int i = 0; i < T; i++, cerr << endl)
            for (int j = 0; j < T; j++)
                cerr << a[i][j] << " ";
        cerr << endl;
    }
};

int n, m;
int key[T][T];
Mat tree[N * 4];


Mat merge(Mat A, Mat B) {
    Mat res;
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++) {
            long long t = 0;
            t += A.a[i][0] * 1ll * B.a[0][j] * key[0][0];
            t += A.a[i][0] * 1ll * B.a[1][j] * key[0][1];
            t += A.a[i][0] * 1ll * B.a[2][j] * key[0][2];

            t += A.a[i][1] * 1ll * B.a[0][j] * key[1][0];
            t += A.a[i][1] * 1ll * B.a[1][j] * key[1][1];
            t += A.a[i][1] * 1ll * B.a[2][j] * key[1][2];

            t += A.a[i][2] * 1ll * B.a[0][j] * key[2][0];
            t += A.a[i][2] * 1ll * B.a[1][j] * key[2][1];
            t += A.a[i][2] * 1ll * B.a[2][j] * key[2][2];
            //for (int x = 0; x < T; x++)
                //for (int y = 0; y < T; y++) 
                    //t += A.a[i][x] * 1ll * B.a[y][j] * key[x][y];
            res.a[i][j] = t % MOD;
        }
    return res;
}

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        for (int i = 0; i < T; i++)
            tree[v].a[i][i] = 1;
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            scanf("%d", &key[i][j]);
}

void add(int v, int ll, int rr, int pos, int val) {
    if (pos < ll || rr <= pos) return;
    //db2(ll, rr);
    if (ll + 1 == rr) {
        //db2(v, pos);
        tree[v].clear();
        if (val == -1) 
            for (int i = 0; i < T; i++)
                tree[v].a[i][i] = 1;
        else {
            tree[v].a[val][val] = 1;
        }
        return;
    }
    add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
    add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void solve() {
    build(0, 0, n);

    for (int i = 0; i < m; i++) {
        int pos, val;
        scanf("%d%d", &pos, &val); pos--; val--;
        
        add(0, 0, n, pos, val);

        int sum = 0;
        for (int x = 0; x < T; x++)
            for (int y = 0; y < T; y++)
                sum = (sum + tree[0].a[x][y]) % MOD;
        printf("%d\n", sum);
        //tree[0].Epr();
        //tree[1].Epr();
        //tree[2].Epr();
    }
}

void stress() {

}


int main(){
#ifdef DEBUG
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