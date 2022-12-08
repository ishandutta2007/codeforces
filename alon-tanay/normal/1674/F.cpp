#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

struct Seg {
    vector<int> seg;
    int n;
    int cnt = 0;
    Seg(int n): n(n) {
        seg.resize(2*n);
    }
    void flip(int i) {
        i += n;
        cnt += 1-seg[i]*2;
        seg[i] = 1 - seg[i];
        for(i >>= 1; i; i >>= 1) {
            seg[i] = seg[i<<1] + seg[(i<<1)|1];
        }
    }
    int sum(int a, int b) {
        int res = 0;
        for(a += n, b += n; a < b; a>>=1, b >>= 1) {
            if(a&1) {
                 res += seg[a++];
            }
            if(b&1) {
                res += seg[--b];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    Seg seg(n*m);
    for(int ri = 0; ri < n; ri ++) {
        for(int ci = 0; ci < m; ci ++) {
            char c;
            cin >> c;
            if(c == '*') {
                seg.flip(ci*n+ri);
            }
        }
    }
    for(int qi = 0; qi < q; qi ++) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        seg.flip(y*n+x);
        cout << seg.cnt - seg.sum(0,seg.cnt) << "\n";
    }
    return 0;
}