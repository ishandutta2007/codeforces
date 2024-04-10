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
#define get gett
const int N = 16;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
char color[N];
int r[N];
int b[N];
int type[N];
vector<int> dp[pw(N)];
int mn[pw(N)];
int mx[pw(N)];
int sumR[pw(N)];
int sumB[pw(N)];
int costR[pw(N)];
int costB[pw(N)];


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c%d%d", &color[i], &r[i], &b[i]);
        type[i] = color[i] == 'R';
    }
}
 /// 'R' = 1

int get(int A, int B) {
    return A * (A - 1) / 2 + A * B - B * (B - 1) / 2;
}

int rec(int mask, int balance) {
    //db2(mask,  balance);
    assert(mn[mask] <= balance && balance <= mx[mask]);
    int &res = dp[mask][balance - mn[mask]];
    if (res == -1) {
        res = INF;
        if (mask == pw(n) - 1) 
            res = 0;
        for (int i = 0; i < n; i++)
            if (((mask >> i) & 1) == 0) {
                int cR = max(0, r[i] - sumR[mask]);
                int cB = max(0, b[i] - sumB[mask]);
                int nbalance = balance - (r[i] - cR) + (b[i] - cB);
                int hasR = -(costR[mask] + balance);
                int hasB = -(costB[mask]);
                int d = min(hasR, hasB);
                hasR -= d;
                hasB -= d;
                //db2(hasR, hasB);
                int needR = max(0, cR - hasR);
                int needB = max(0, cB - hasB);
                int need = max(needR, needB);
                int nmask = mask | (1 << i);
                //db3(need, mask, nmask);
                res = min(res, need + rec(nmask, nbalance));
            }
        //db3(mask, balance, res);
    }
    return res;
}

void solve() { 
    for (int mask = 0; mask < pw(n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                sumR[mask] += type[i];
                sumB[mask] += (1 - type[i]);
                costR[mask] += r[i];       
                costB[mask] += b[i];
            }
        }
        mx[mask] = sumB[mask] * (sumB[mask] - 1) / 2 + sumB[mask] * sumR[mask];
        mn[mask] = -sumR[mask] * (sumR[mask] - 1) / 2 - sumB[mask] * sumR[mask];
        dp[mask].assign(mx[mask] - mn[mask] + 1, -1);
        //db3(mask, mn[mask], mx[mask]);
    }
    //db(rec(2, 0));
    cout << rec(0, 0) + n << endl;
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