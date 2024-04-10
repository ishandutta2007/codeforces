#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
using namespace std;
constexpr int N = 100005;
int qry(int x, int y, int z) {
    printf("? %d %d %d\n", x, y, z);
    fflush(stdout);
    int w;
    scanf("%d", &w);
    return w;
}

int a[N], res[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t -- > 0) {
        int n;
        scanf("%d", &n);
        n /= 3;
        for(int i = 1; i <= n * 3; i++) { res[i] = -1; }
        for(int i = 0; i < n; i++) { a[i] = qry(i * 3 + 1, i * 3 + 2, i * 3 + 3); }
        int a0 = -1, a1 = -1;
        for(int i = 0; i < n; i++) if(a[i] == 1 && a1 == -1) { a1 = i * 3; }
            else
                if(a[i] == 0 && a0 == -1) { a0 = i * 3; }
        int w0 = 0, w1 = 0;
        if(!qry(a1 + 1, a1 + 2, a0 + 1)) { w1 = a1 + 3, w0 = a0 + 1; }
        else
            if(!qry(a1 + 1, a1 + 2, a0 + 2)) { w1 = a1 + 3, w0 = a0 + 2; }
            else
                if(!qry(a1 + 1, a1 + 2, a0 + 3)) { w1 = a1 + 3, w0 = a0 + 3; }
                else
                    if(!qry(a1 + 1, a0 + 1, a0 + 2)) { w1 = a1 + 1, w0 = a0 + 1; } //1,1,* | 0,0,*
                    else
                        if(!qry(a1 + 1, a0 + 1, a0 + 3)) { w1 = a1 + 1, w0 = a0 + 1; }
                        else
                            if(!qry(a1 + 1, a0 + 2, a0 + 3)) { w1 = a1 + 1, w0 = a0 + 2; }
                            else { throw; }
        res[w1] = 1, res[w0] = 0;
        for(int i = 1; i <= n * 3; i++)
            if(res[i] == -1) { res[i] = qry(i, w1, w0); }
        int tt = 0;
        for(int i = 1; i <= n * 3; i++) if(res[i] == 0) { ++tt; }
        printf("! %d", tt);
        for(int i = 1; i <= n * 3; i++) if(res[i] == 0) { printf(" %d", i); }
        puts("");
        fflush(stdout);
    }
    return 0;
}