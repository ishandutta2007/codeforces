#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)2e5 + 100;
int n, m;
long long a[maxn];
long long ans;
void calc2(long long x) {
    long long cur = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < x) {
            cur += x - a[i];
        } else {
            cur += min(a[i] % x, x - a[i] % x);
        }
    }
    ans = min(ans, cur);
}
void calc(long long x) {
    for(long long i = 2; i <= 1e4; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                x /= i;
            }
            calc2(i);
        }
    }
    for(long long i = 1e4 + 1; i * i <= x; i+=2) {
        if(x % i == 0) {
            calc2(i);
            calc2(x/i);
            return;
        }
    }
    if(x > 1) {
        calc2(x);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = n;
    calc(2);

    while(clock() < CLOCKS_PER_SEC * 2) {
        int pos = (rand() * 1ll * rand() + rand()) % n;
        if(a[pos] > 1) {
            calc(a[pos]);
        }
        if(a[pos] > 2) {
            calc(a[pos]-1);
        }
        calc(a[pos]+1);
    }
    cout << ans << "\n";
}