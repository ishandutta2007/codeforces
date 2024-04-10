#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ld long double
#define f first
#define s second

using namespace std;

struct Trap {
    int l, r, d;
};

int m,n,k,t;
vector<int> as;
vector<Trap> traps;

int tim(int c) {
    int weak = as[m-c];
    ll res = n - 1;
    vector<int> fix(n+2);
    for(Trap trap : traps) {
        if(trap.d > weak) {
            fix[trap.l] = max(fix[trap.l],trap.r); 
        }
    }
    int idx = 0;
    int st = 0;
    int en = 0;
    for(int i = 1; i <= n + 1; i ++) {
        if(!fix[i]) { continue; }
        if(en < i) {
            res += (en - st+1) * 2;
            st = i;
            en = fix[i];
        } else {
            en = max(en,fix[i]);
        }
    }
    res += (en-st+1) * 2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k >> t;
    as.resize(m);
    for(int &a : as) {
        cin >> a;
    }
    traps.resize(k);
    for(Trap &trap : traps) {
        cin >> trap.l >> trap.r >> trap.d;
    }
    as.push_back(1e9);
    sort(as.begin(),as.end());

    int l = 0, r = m;
    while(l < r) {
        int mid = (l+r+1)/2;
        if(tim(mid) <= t) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
}