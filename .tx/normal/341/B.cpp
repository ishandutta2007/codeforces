#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(n) for (int i = 0; i < n; ++i)
#define foj(n) for (int j = 0; j < n; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

const int MAXN = 131334;

int d[MAXN + 1];

const int INF = 1e9;

// File names!!!

int main() {
    //openfiles("test");
    int n;
    sci(n);
    vei a(n);
    foi(n) sci(a[i]);


    d[0] = -INF;
    for (int i=1; i<=n; ++i)
        d[i] = INF;

    for (int i=0; i<n; i++) {
        int j = int (upper_bound (d, d + n, a[i]) - d);
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    foi(n + 1) if (d[i] != INF) ans = i;
    cout << ans;

    puts("");
    return 0;
}//uximem