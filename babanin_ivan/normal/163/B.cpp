#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, k;
ld h;
vector <int> ans;
pair<int, pair <ld, int> > a[200000]; 

bool check(ld t) {
    ans.clear();
    for (int i = 0; i < n; ++i)
        if ((ld(ans.size() + 1) * h / a[i].sec.fir) <= t)
            ans.pb(a[i].second.second);
    if (ans.size() >= k)
        return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k >> h;
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i].first);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i].sec.fir = ld(x);
        a[i].sec.sec = i;
    }
    sort(a, a + n);
    ld l = 0;
    ld r = 1000000001.0;
    for (int it = 0; it < 200; ++it) {
        ld m = (l + r) / 2.0;
        if (check(m))
            r = m;
        else l = m;
    }
    bool f = check(r);
    for (int i = 0;  i < k; ++i)
        printf("%d ", ans[i] + 1);
    return 0;
}