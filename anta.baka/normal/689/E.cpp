#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull P = 1000000007;
const int N = 200001;

ull f[N]; // fact

ull pm(ull n, ull p) {
    if(!p) return 1;
    if(p % 2) return (pm(n, p-1) * n) % P;
    ull t;
    return ((t = pm(n, p/2)) * t) % P;
}

ull C(ull n, ull k) {
    return (f[n] * pm((f[k] * f[n-k]) % P, P-2)) % P;
}

int l[N], r[N], tr1[5*N], tr2[5*N];

void inc1(int l, int r, int n) {
    for(l += n, r += n; l <= r; l = (l + 1)>>1, r = (r - 1)>>1) {
        if(l&1) tr1[l]++;
        if(!(r&1)) tr1[r]++;
    }
}

int get1(int pos, int n) {
    int res = tr1[pos+=n];
    for(pos >>= 1; pos; pos >>= 1)
        res += tr1[pos];
    return res;
}

void inc2(int l, int r, int n) {
    for(l += n, r += n; l <= r; l = (l + 1)>>1, r = (r - 1)>>1) {
        if(l&1) tr2[l]++;
        if(!(r&1)) tr2[r]++;
    }
}

int get2(int pos, int n) {
    int res = tr2[pos+=n];
    for(pos >>= 1; pos; pos >>= 1)
        res += tr2[pos];
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> x;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        x[l[i]]; x[r[i]];
    }
    int cnt = 0;
    for(auto &w : x)
        w.second = cnt++;
    for(int i = 0; i < n; i++)
        inc1(x[l[i]], x[r[i]], cnt),
        inc2(x[l[i]], x[r[i]]-1, cnt);
    ull res = 0;
    f[0] = 1;
    for(int i = 1; i <= N; i++)
        f[i] = (f[i-1] * i) % P;
    for(int i = 0, t; i < cnt; i++)
        if((t = get1(i, cnt)) >= k)
            res = (res + C(t, k)) % P;
    auto it = x.begin();
    for(int i = 0, t; i < cnt-1; i++, it++) {
        auto next = it;
        next++;
        if((t = get2(i, cnt)) >= k)
            res = (res + (C(t, k) * ((*next).first - (*it).first - 1)) % P) % P;
    }
    cout << res;
    return 0;
}