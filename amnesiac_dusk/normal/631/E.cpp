/*
 * 	I believe if I knew where I was going Id lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today its okay to be not okay
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}
class ConvexHullDynamic
{
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
public:
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}
    void addLine(ll a, ll b)
    {
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if ((isMax && it->b < b) || (!isMax && it->b > b))
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
ConvexHullDynamic dp(1);  // 0 is when you need a minimum convex hull


int a[200005];
int prea[200005];
void solve()
{
	int n;
	cin>>n;
	ll sum=0;
	dp.addLine(0, 0);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		prea[i]=prea[i-1]+a[i];
		sum+=a[i]*i;
		dp.addLine(i,-prea[i]);
	}
	ll ans=0;
	for(int i=1; i<=n; i++) {
//		cout<<-dp.getBest(a[i])+prea[i]-a[i]*i<<endl;
		ans=max(prea[i]-a[i]*i+dp.getBest(a[i]),ans);
	}
	cout<<sum+ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}