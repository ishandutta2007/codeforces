#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t, w, l;

bool allowed(ll x) {
    for (ll i = 0; i < 1<<4; i++) {
        ll a = w, b = l, c = w, d = l;
        if (i&1) a--;
        else b--;
        if (i&2) b--;
        else c--;
        if (i&4) c--;
        else d--;
        if (i&8) d--;
        else a--;
        if (a%x==0 && b%x==0 && c%x==0 && d%x==0) {
            return true;
        }
    }
    return false;
}


int main() {
    scanf("%lld", &t);
    for (ll i =0; i < t; i++) {
        scanf("%lld %lld", &w, &l);
        vector<int> ans;
        for (ll x = 1; x*x <= 2*l + 2*w - 4; x++) {
            if ((2*l + 2*w - 4) % x == 0) {
                if (allowed(x)) ans.push_back(x);
                if (x*x != 2*l + 2*w - 4) {
                    if (allowed((2*l + 2*w - 4) / x)) ans.push_back((2*l + 2*w - 4) / x);
                }
            }
        }
        printf("%lu ", ans.size());
        sort(ans.begin(), ans.end());
        for (int x: ans) {
            printf("%d ", x);
        }
        printf("\n");
    }
}