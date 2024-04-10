/*
 * 	If you gave me a chance
 * 		I'll take it
 * 			It's a shot in the dark
 * 				But I will make it:D
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

class ConvexHullDynamic
{
public:
    struct Line
    {
        ll a, b;
        f80 xLeft;
        enum Type {line, maxQuery, minQuery} type;
        ll val;
        explicit Line(ll aa=0, ll bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        ll valueAt(ll x) const { return a*x+b; }
        friend bool areParallel(const Line& l1, const Line& l2) { return l1.a==l2.a; }
        friend f80 intersectX(const Line& l1, const Line& l2) { return areParallel(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const Line& l2) const
        {
            if (l2.type == line)
                return this->a < l2.a;
            if (l2.type == maxQuery)
                return this->xLeft < l2.val;
            if (l2.type == minQuery)
                return this->xLeft > l2.val;
        }
    };
    bool isMax;
    set<Line>  hull;
    bool hasPrev(set<Line>::iterator it) { return it!=hull.begin(); }
    bool hasNext(set<Line>::iterator it) { return it!=hull.end() && next(it)!=hull.end(); }
    bool irrelevant(const Line& l1, const Line& l2, const Line& l3) { return intersectX(l1,l3) <= intersectX(l1,l2); }
    bool irrelevant(set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
               && (isMax && irrelevant(*prev(it), *it, *next(it))
                       || !isMax && irrelevant(*next(it), *it, *prev(it)) );
    }
    set<Line>::iterator updateLeftBorder(set<Line>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it)) return it;
        f80 val = intersectX(*it, isMax?*prev(it):*next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }
//public:
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}
    void addLine(ll a, ll b)
    {
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = hull.erase(it);
            else
                return;
        }
        it = hull.insert(it, l3);
        if (irrelevant(it)) { hull.erase(it); return; }
        while (hasPrev(it) && irrelevant(prev(it))) hull.erase(prev(it));
        while (hasNext(it) && irrelevant(next(it))) hull.erase(next(it));
        it = updateLeftBorder(it);
        if (hasPrev(it))
            updateLeftBorder(prev(it));
        if (hasNext(it))
            updateLeftBorder(next(it));
    }
    ll getBest(ll x) const
    {
        Line q;
        q.val = x;
        q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;
        auto bestLine = hull.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }
};
ConvexHullDynamic dpHull(1);  // 0 is when you need a minimum convex hull

void solve() {
	int n;
	cin>>n;
	vector<pii> pts;
	int x,y;
	fr(i,1,n) {
		cin>>x>>y;
		dpHull.addLine(-x, -x*x+y);
	}
	cout<<sz(dpHull.hull)-1<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}