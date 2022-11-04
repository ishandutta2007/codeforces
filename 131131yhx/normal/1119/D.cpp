#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define PII pair <int, int>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long ll;

int n, X[100010];

ll Ans[100010];

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &X[i]);
    sort(X + 1, X + n + 1);
    n = unique(X + 1, X + n + 1) - X - 1;
    vector <int> V(0);
    V.push_back(1);
    for(int i = 1; i < n; i++) V.push_back(X[i + 1] - X[i]);
    sort(V.begin(), V.end());
    Ans[0] = 0;
    for(int i = 1; i < n; i++) Ans[i] = Ans[i - 1] + V[i];
    int q;
    scanf("%lld", &q);
    while(q--) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        int det = r - l;
        int w = lower_bound(V.begin(), V.end(), det + 1) - V.begin();
        w--;
        if(w == -1) {printf("%lld ", (det + 1) * n); continue;}
        ll nwans = Ans[w];
        printf("%lld ", (det + 1) * n - (w) * (det + 1) + Ans[w]);
    }
    putchar('\n');
    return 0;
}