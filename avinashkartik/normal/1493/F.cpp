#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, p[N], r[N], c[N];

bool R(int st, int x, int flag = 0) {
    int sz = min(x, n - x), f;
    if (r[sz] == -1) {
        cout << "? " << sz << " " << m << " ";
        if (!flag) deb4(st, 1, x + st, 1)
        else deb4(st, 1, n - x + 1, 1)
        cin >> f;
        return f;
    }
    return r[sz];
}

bool q1(int st, int x) {
    if (n - x + 1 == st) return 1;
    int no = n - st + 1;
    int f1;
    if ((no / x) % 2 == 1){
        f1 = R(st, (no - x) / 2);
        if (f1 == 0) return f1;
        return R(st, (no - x) / 2, 1);
    } else {
        f1 = R(st, no / 2);
        if (f1 == 0) return f1;
        return q1(no / 2 + st, x);
    }
}

bool C(int st, int x, int flag = 0) {
    int sz = min(x, m - x), f;
    if (c[sz] == -1) {
        cout << "? " << n << " " << sz << " ";
        if (!flag) deb4(1, st, 1, x + st)
        else deb4(1, st, 1, m - x + 1)
        cin >> f;
        return f;
    }
    return c[sz];
}

bool q2(int st, int x) {
    if (m - x + 1 == st) return 1;
    int no = m - st + 1;
    int f1;
    if ((no / x) % 2 == 1){
        f1 = C(st, (no - x) / 2);
        if (f1 == 0) return f1;
        return C(st, (no - x) / 2, 1);
    } else {
        f1 = C(st, no / 2);
        if (f1 == 0) return f1;
        return q2(no / 2 + st, x);
    }
}

void solve() {
    mset(r, -1);
    mset(c, -1);
    cin >> n >> m;
    r[n] = c[m] = 1;
    vll f;
    ll x = n;
    while (x > 1) {
        f.pb(p[x]);
        x /= p[x];
    }
    x = n;
    for (auto it : f) {
        if (q1(1, x / it) == 1) {
            r[x / it] = 1;
            x /= it;
        } else {
            r[x / it] = 0;
        }
    }
    vll f1;
    ll y = m;
    while (y > 1) {
        f1.pb(p[y]);
        y /= p[y];
    }
    y = m;
    for (auto it : f1) {
        if (q2(1, y / it) == 1) {
            c[y / it] = 1;
            y /= it;
        } else {
            c[y / it] = 0;
        }
    }
    x = n / x;
    y = m / y;
    int ct1 = 1, ct2 = 1;
    while (x > 1) {
        int spf = p[x], ct = 0;
        while (x % spf == 0) {
            ct++;
            x /= spf;
        }
        ct1 *= (ct + 1);
    }
    while (y > 1) {
        int spf = p[y], ct = 0;
        while (y % spf == 0) {
            ct++;
            y /= spf;
        }
        ct2 *= (ct + 1);
    }
    deb2('!', ct1 * ct2)
}

int main() {
    int test = 1;
    for (int i = 2; i < N; i++) {
        if (p[i]) continue;
        for (int j = i; j < N; j += i) {
            if (p[j] == 0) p[j] = i;
        }
    }
    // cin >> test;
    for (int i = 1; i <= test; i++) {
        solve();
    }
}