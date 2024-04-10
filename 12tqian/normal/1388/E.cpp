#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll BIG = 1e8;
const long double INF = 1e18;

struct convex_hull_trick {
    struct line {
        ll m, b; ld x, val;
        bool is_query;
        line(ll _m = 0, ll _b = 0){
            m = _m, b = _b, val = 0, x = -INF, is_query = false;
        }
        ld eval(ld x) const { return m * x + b; }
        bool parallel(const line &l) const { return m == l.m; }
        long double intersect(const line &l) const {
            return parallel(l) ? INF : 1.0 * (l.b - b) / (m - l.m);
        }
        bool operator < (const line &l) const {
            if(l.is_query) return x < l.val;
            else return m < l.m;
        }
    };
    set<line> hull;
    bool hull_prev(set<line> :: iterator it) { return it != hull.begin(); }
    bool hull_next(set<line> :: iterator it) { return it != hull.end() && next(it) != hull.end(); }
    bool bad(const line &l1, const line &l2, const line &l3) { return l1.intersect(l3) <= l1.intersect(l2); }
    bool bad(set<line> :: iterator it) { return hull_prev(it) && hull_next(it) && bad(*prev(it), *it, *next(it)); }
    set<line> :: iterator update(set<line> :: iterator it) {
        if(!hull_prev(it)) return it;
        long double x = it -> intersect(*prev(it));
        line tmp(*it); tmp.x = x;
        it = hull.erase(it);
        return hull.insert(it, tmp);
    }
    void add_line(long long m, long long b) {
        line l(m, b);
        set<line> :: iterator it = hull.lower_bound(l);
        if(it != hull.end() && l.parallel(*it)) {
            if(it -> b < b) it = hull.erase(it);
            else return;
        }
        it = hull.insert(it, l);
        if(bad(it)) return (void) hull.erase(it);
        while(hull_prev(it) && bad(prev(it))) hull.erase(prev(it));
        while(hull_next(it) && bad(next(it))) hull.erase(next(it));
        it = update(it);
        if(hull_prev(it)) update(prev(it));
        if(hull_next(it)) update(next(it));
    }
    ld query(ld x) const {
    if(hull.empty()) return -INF;
        line q; q.val = x, q.is_query = 1;
        set<line> :: iterator it = --hull.lower_bound(q);
        return it -> eval(x);
    }
};
convex_hull_trick cht_max;
convex_hull_trick cht_min;
ld get_time(ll x, ll y, ll speed){
    ld dist = y - x;
    return dist / speed;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<ll, pair<ll, ll>>> v (n);
    for(int i = 0; i < n; i++) cin >> v[i].second.first >> v[i].second.second >> v[i].first;
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        v[i].second.first -= v[i].first*BIG;
        v[i].second.second -= v[i].first*BIG;
    }
    for(int i = 0; i < n; i++){
        cht_max.add_line(v[i].first, v[i].second.second);
        cht_min.add_line(-v[i].first, -v[i].second.first);
    }
    vector<pair<ld, int>> events;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i].first == v[j].first) continue;
            ll speed = v[i].first - v[j].first;
            ld st = get_time(v[i].second.second, v[j].second.first, speed);
            ld ed = get_time(v[i].second.first, v[j].second.second, speed);
            pair<ld, int> beg = make_pair(st, 1);
            pair<ld, int> fin = make_pair(ed, 0);
            events.push_back(beg);
            events.push_back(fin);
        }
    }
    sort(events.begin(), events.end());
    int cross = 0;
    ld ans = cht_max.query(0) + cht_min.query(0);
    for(auto e: events){
        ld ti = e.first;
        int ty = e.second;
        if(cross == 0) ans = min(ans, cht_max.query(ti) + cht_min.query(ti));
        if(ty == 0) cross++;
        else cross--;
        if(cross == 0) ans = min(ans, cht_max.query(ti) + cht_min.query(ti));
    }
    cout << fixed << setprecision(100) << ans << '\n';
    return 0;
}