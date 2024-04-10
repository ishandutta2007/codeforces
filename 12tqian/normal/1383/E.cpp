#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct mi {
    int val;
    explicit operator int() const { return val; }
    mi() { val = 0; }
    mi(const ll& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
    mi operator-() const { return mi(-val); }
    mi& operator+=(const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator*=(const mi& m) { val = (ll)val*m.val%MOD;
        return *this; }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a,MOD-2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

int n, a[MAX], nxt[MAX], block[MAX], zeros[MAX];
mi dp[MAX], fwd[MAX];
bool used[MAX];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; n = (int) s.size();
    for(int i = 0; i < n; i++) a[i] = s[i] - '0';
    int bad = 0;
    for(int i = 0; i < n; i++) bad += a[i];
    if(bad == n || bad == 0){
        cout << n << '\n';
        return 0;
    }
    int rec = -1;
    for(int i = n - 1; i >= 0; i--){
        nxt[i] = rec;
        if(a[i]) rec = i;
    }
    int le = n - 1;
    int ri = n - 1;
    int big = 0;
    while(ri != -1){
        while(le != 0 && a[le - 1] == a[ri]) le--;
        if(a[ri] == 0) big = max(big, ri - le + 1);
        else for(int i = le; i <= ri; i++) block[i] = big;
        le--;
        ri = le;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            int cnt = 0;
            for(int j = i - 1; j >= 0; j--){
                if(a[j] == 0) cnt++;
                else break;
            }
            zeros[i] = cnt;
        }
    }
    mi tot = 0; int last = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == 0) last++;
        else break;
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == 0) continue;
        dp[i] = tot + last + 1;
        for(int j = 0; j <= zeros[i]; j++){
            tot -= fwd[j];
            fwd[j] = dp[i];
            tot += fwd[j];
        }
    }
    int first = 0; int first_one;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) first++;
        else {
            first_one = i;
            break;
        }
    }
    mi ans = dp[first_one] * (first + 1);
    cout << ans << '\n';
    return 0;
}