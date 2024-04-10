#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ld long double
#define f first
#define s second

using namespace std;

struct Seg {
    vector<int> seg;
    int n;
    Seg(vector<int> xs): n(xs.size()) {
        seg.resize(2*n);
        for(int i = 0; i < n; i ++) {
            seg[i+n] = xs[i];
        }
        for(int i = n - 1; i; i --) {
            seg[i] = max(seg[i<<1],seg[(i<<1)|1]);
        }
    }
    int query(int a, int b) {
        int res = 0;
        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if(a&1) {
                res = max(res,seg[a++]);
            }
            if(b&1) {
                res = max(res,seg[--b]);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> mons(n);
        for(int &m : mons) {
            cin >> m;
        }
        Seg seg(mons);
        int m;
        cin >> m;
        vector<pi> heros(m);
        for(pi &p : heros) {
            cin >> p.f >> p.s;
        }
        sort(heros.begin(),heros.end());
        vector<pi> hs;
        for(pi hero : heros) {
            while(!hs.empty() && hs.back().s <= hero.s) {
                hs.pop_back();
            }
            hs.push_back(hero);
        }
        int sz = hs.size();
        if(seg.query(0,n) > hs[sz-1].f) {
            cout << "-1\n";
            continue;
        }
        int idx = 0;
        int cnt = 0;
        while(idx < n) {
            int l = 1, r = n - idx;
            while(l < r) {
                int mid = (l+r+1)/2;
                int mx = seg.query(idx,idx+mid);
                int lh = 0, rh = hs.size() - 1;
                while(lh < rh) {
                    int mh = (lh+rh)/2;
                    if(hs[mh].f >= mx) {
                        rh = mh;
                    } else {
                        lh = mh + 1;
                    }
                }
                if(hs[lh].s >= mid) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            idx += l;
            cnt ++;
        }
        cout << cnt << "\n";
    }
}