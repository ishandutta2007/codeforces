#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
const int BIG = 1e6;
vector<int> h_start[MAX], h_end[MAX], v_start[MAX], v_end[MAX];
vector<pair<int, int>> h_seg[MAX], v_seg[MAX];
template<class T> struct Seg {
    const T ID = 0; T comb(T a, T b) { return a + b; }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, T val) {
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
    void add(int p, int val){
        upd(p, query(p, p) + val);
    }
};
Seg<long long> seg;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<pair<int, int>, int>> hori(n), vert(m);
    for(int i = 0; i < n; i++) cin >> hori[i].second >> hori[i].first.first >> hori[i].first.second;
    for(int i = 0; i < m; i++) cin >> vert[i].second >> vert[i].first.first >> vert[i].first.second;
    hori.emplace_back(make_pair(0, BIG), 0), hori.emplace_back(make_pair(0, BIG), BIG);
    vert.emplace_back(make_pair(0, BIG), 0), vert.emplace_back(make_pair(0, BIG), BIG);
    n += 2; m += 2;
    sort(hori.begin(), hori.end()); sort(vert.begin(), vert.end());
    for(auto h: hori){
        h_start[h.first.first].push_back(h.second);
        h_end[h.first.second].push_back(h.second);
        h_seg[h.second].push_back(h.first);
    }
    for(auto v: vert){
        v_start[v.first.first].push_back(v.second);
        v_end[v.first.second].push_back(v.second);
        v_seg[v.second].push_back(v.first);
    }
    long long edges = 0, vertices = 0;
    seg.init(BIG + 1);
    for(int i = 0; i <= BIG; i++){
        for(int v: v_start[i]) seg.add(v, 1);
        for(auto h: h_seg[i]){
            long long cross_vertices = seg.query(h.first, h.second) ;
            long long extra_vertices = 2 - seg.query(h.first, h.first) - seg.query(h.second, h.second);
            vertices += (cross_vertices + extra_vertices);
            edges += (cross_vertices + extra_vertices - 1);
        }
        for(int v: v_end[i]) seg.add(v, -1);
    }
    seg.init(BIG + 1);
    for(int i = 0; i <= BIG; i++){
        for(int h: h_start[i]) seg.add(h, 1);
        for(auto v: v_seg[i]){
            long long cross_vertices = seg.query(v.first, v.second);
            long long extra_vertices = 2 - seg.query(v.first, v.first) - seg.query(v.second, v.second);
            vertices += extra_vertices;
            edges += (cross_vertices + extra_vertices - 1);
        }
        for(int h: h_end[i]) seg.add(h, -1);
    }
    cout << edges - vertices + 2 - 1 << '\n';
    return 0;
}