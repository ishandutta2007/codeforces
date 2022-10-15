
#include <bits/stdc++.h>
#define int long long
using namespace std;

#define SZ(x) (int)(x).size()
#define REP(i,n) for (int i = 0; i<n; ++i)

const int maxn = 1e5+5;
int a[maxn];


int work(vector<int> b) {
    vector<int> cnt(maxn);
    REP(i,SZ(b)) {
        ++cnt[b[i]];
    }
    int nodd = 0;
    REP(i, maxn) {
        nodd += cnt[i] % 2 == 1;
    }
    int bad = -1;
    int re = 0;
    if (nodd == SZ(b)%2) REP(i, SZ(b)) {
        if (i < SZ(b)/2) {
            cnt[b[i]] -= 2;
            if (cnt[b[i]] < 0) {
                bad = i; break;
            }
        }
        else if (SZ(b) % 2 == 1 && i == SZ(b)/2) {
            nodd -= cnt[b[i]] % 2;
            --cnt[b[i]];
            nodd += cnt[b[i]] % 2;
            if (nodd != (0) || cnt[b[i]] < 0) {
                bad = i; break;
            }
        }else{
            if (b[i] != b[SZ(b)-i-1]) {
                bad = i; break;
            }
        }
    }
//    assert(bad != -1);
    return bad;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n; cin>>n;
    REP(i,n) {
        cin>>a[i];
    }

    int l=0, r = n-1;
    while (l < r && a[l] == a[r]) {
        ++l; --r;
    }
    if (l >= r) {
        cout<<n*(n+1)/2<<endl; return 0;
    }

    assert(a[l] != a[r]);
    long long re = (l+1) * (l+1);
//    cout<<re<<endl;
    vector<int> b;
    for (int i = l; i<=r; ++i) b.push_back(a[i]);
    int m1 = work(b); reverse((b).begin(), b.end()); int m2 = work(b);
//    cout<<m1<<endl;
//    cout<<m2<<endl;
    if (m1 == -1) {
        assert(m2 == -1);
        cout<<0<<endl;
    }else
        cout<<re+(m1+m2) * (l+1)<<endl;
}