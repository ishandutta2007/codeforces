#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 200100;
struct Tree {
	vector<ll> v;
	int M;
	void init(int n) {
		M=1;
		while (M <= n) M *= 2;
		v.resize(2*M);
	}
	void add(int pos, int val) {
		//printf("add %d %d\n", pos, val);
		pos += M;
		//printf("set value %d = %d \n", pos, val);
		v[pos] = val;
		while (pos > 1) {
			pos /= 2;
			v[pos] = v[pos*2] + v[pos*2+1];
			//printf("set value %d = %d \n", pos, v[pos]);
		}
	}
	ll get(int posL, int posR) {
		if (posR <= posL) return 0;
		//printf("get %d %d\n", posL, posR);
		posL += M;
		posR += M;
		ll sum = v[posL];
		//printf("get value %d = %d\n", posL, sum);
		while (posL+1 < posR) {
			if (posL%2==0) sum += v[posL+1];
			if (posR%2==1) sum += v[posR-1];
			//printf("get value %d %d = %d\n", posL, posR, sum);
			posL /= 2;
			posR /= 2;
		}
		return sum;
	}
};

int n,k,a,b,q;
Tree TA, TB;
int t[maxn];

int main() {
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	TA.init(n);
	TB.init(n);
	FOR(i,q) {
		int qty;
		scanf("%d", &qty);
		if (qty==1) {
			int day, ordn;
			scanf("%d%d", &day, &ordn);
			t[day] += ordn;
			TB.add(day, min(t[day],b));
			TA.add(day, min(t[day],a));
		} else {
			int que;
			scanf("%d", &que);
			cout << TB.get(1, que) + TA.get(que+k, n+1) << "\n";
		}
	}
	return 0;
}