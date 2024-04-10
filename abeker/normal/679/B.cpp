#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

ll M;
vector <ll> a;

ll cube(ll x) {
    return x * x * x;
}

bool check() {
    for (int i = 1; i < a.size(); i++)
        if (a[i - 1] > a[i]) 
            return false;
    
    ll pref = 0;
    for (int i = 0; i < a.size(); i++) {
        pref += cube(a[i]);
        if (pref >= cube(a[i] + 1)) 
            return false;
    }
    
    return pref <= M;
}

int main() {
    scanf("%lld", &M);
    ll sum = 1;
    a.push_back(1);
    while (sum <= M) {
        ll lo = a.back(), hi = (ll)1e6;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (cube(mid + 1) - cube(mid) > sum) hi = mid;
            else lo = mid + 1;
        }
        a.push_back(lo);
        sum += cube(lo);
    }
    a.pop_back();
    
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        ll lo = a[i], hi = (ll)1e6;
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            a[i] = mid;
            if (check()) lo = mid;
            else hi = mid - 1;
        }
        a[i] = lo;
    }
    
    sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += cube(a[i]);
        
    printf("%d %lld\n", a.size(), sum);
    
    return 0;
}