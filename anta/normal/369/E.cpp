#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#include <memory>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

template<typename T> struct FenwickTree {
    vector<T> v;
    FenwickTree(int n): v(n, 0) {}
    void add(int i, T x) {
        for(; i < (int)v.size(); i |= i+1) v[i] += x;
    }
    T sum(int i) {
        T r = 0;
        for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
        return r;
    }
};

//: mp(-x[i], y[i])pointsmp(-left+1,right)
//query((right,bottom),i): _open_ interval ([0,right),[0,bottom))
//points((x,y),val)
//ans(i): ans[query[j].second] += sum(...)
template<typename T, typename V>
void twoDimensionalSumQuery(vector<pair<pair<T,T>,V> > points, vector<pair<pair<T,T>,int> > queries, vector<V> &ans) {
    int n = points.size(), m = queries.size();
    vector<T> positions;
    rep(i, n) positions.pb(points[i].first.second);
    sort(all(positions));
    positions.erase(unique(all(positions)), positions.end());
    int p = positions.size();
    FenwickTree<V> t(p);
    sort(all(points)); sort(all(queries));
    int left = 0;
    rep(i, m) {
        T x = queries[i].first.first;
        while(left < n && points[left].first.first < x) {
            int j = lower_bound(all(positions), points[left].first.second) - positions.begin();
            t.add(j, points[left].second);
            left ++;
        }
        int y = lower_bound(all(positions), queries[i].first.second) - positions.begin();
        ans[queries[i].second] += t.sum(y);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vpii lr;
    rep(i, n) {
        int l, r;
        scanf("%d%d", &l, &r);
        lr.pb(mp(l,r));
    }
    sort(all(lr));
    vector<pair<pii,int> > points;
    rep(i, n) points.pb(mp(mp(-lr[i].first, lr[i].second), 1));
    vector<pair<pii,int> > queries;
    rep(i, m) {
        int cnt;
        scanf("%d", &cnt);
        int prev = 0;
        rep(j, cnt+1) {
            int p;
            if(j == cnt) p = 1000001;
            else scanf("%d", &p);
            queries.pb(mp(mp(-(prev), p), i));
            prev = p;
        }
    }
    vi ans(m, 0);
    twoDimensionalSumQuery(points, queries, ans);

    rep(i, m) cout << n - ans[i] << endl;

    return 0;
}