#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

const int M = 50;

vi MERGE(vi a, vi b) {
    vi res(M);
    int ai = 0;
    int bi = 0;
    for(int i = 0; i < M; i ++) {
        if(a[ai] < b[bi]) {
            res[i] = a[ai];
            ai ++;
        } else {
            res[i] = b[bi];
            bi ++;
        }
    }
    return res;
}

struct Seg {
    vector<vi> seg;
    int n;
    void pull(int j) {
        seg[j] = MERGE(seg[j<<1],seg[(j<<1)|1]);
    }
    Seg(vi xs) {
        n = xs.size();
        seg.resize(n*2);
        for(int i = 0; i < n; i ++) {
            seg[i+n].resize(M);
            seg[i+n][0] = xs[i];
            for(int j = 1; j < M; j ++) {
                seg[i+n][j] = INF;
            }
        }
        for(int i = n - 1; i; i --) {
            pull(i);
        }
    }
    vi query(int a, int b) {
        vi merge(M,INF);
        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if(a&1) {
                merge = MERGE(merge,seg[a++]);
            }
            if(b&1) {
                merge = MERGE(merge,seg[--b]);
            }
        }
        return merge;
    }
};

int RES(vi t) {
    
    int mn = INF;
    for(int i = 0; i < M; i ++) {
        for(int j = i + 1; j < M; j ++) {
            mn = min(mn,t[i]|t[j]);
        }
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi xs(n);
        for(int &x : xs) {
            cin >> x;
        }
        Seg seg(xs);
        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            vi res = seg.query(l-1,r);
            cout << RES(res) << "\n";
        }
    }
    return 0;
}