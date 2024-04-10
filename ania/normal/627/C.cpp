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

const int maxn = 200200;
const ll inf = 100000000100000000LL;
const int infI = 1000100100;

struct Tree {
	vector<int> v,t;
	int M;
	void init(int n) {
		M=1;
		while (M <= n) M *= 2;
		v.resize(2*M);
		t.resize(M,infI);
		FOR(i,M) v[i+M]=i;
	}
	void add(int pos, int val) {
		//printf("add %d %d\n", pos, val);
		//printf("set value %d = %d \n", pos, val);
		t[pos] = val;
		v[pos+M] = pos;
		pos += M;
		while (pos > 1) {
			pos /= 2;
			if (t[v[pos*2]] < t[v[pos*2+1]]) v[pos] = v[pos*2];
			else v[pos] = v[pos*2+1];
			//printf("set value %d = %d \n", pos, v[pos]);
		}
	}
	int get(int posL, int posR) {
		if (posR <= posL) return -1;
		//printf("get %d %d\n", posL, posR);
		int res = posL;
		posL += M;
		posR += M;
		//printf("get value %d = %d\n", posL, res);
		while (posL+1 < posR) {
			if (posL%2==0 && t[v[posL+1]] < t[res]) res = v[posL+1];
			if (posR%2==1 && t[v[posR-1]] < t[res]) res = v[posR-1];
			//printf("get value %d %d = %d\n", posL, posR, res);
			posL /= 2;
			posR /= 2;
		}
		return res;
	}
};

Tree T;
int n,m,d;
int x[maxn], p[maxn];

ll rec(int L, int R, int have) {
	//printf("rec %d %d %d\n", L, R, have);
	if (x[R]-x[L] <= have) return 0;
	if (x[R]-x[L] <= n) return 1LL * (x[R]-x[L]-have) * p[L];
	if (L+1 >= R) return inf;
	
	int M = T.get(L+1, R);
	ll res = 1LL*(n-have)*p[L];
	if (x[M]-x[L] <= n) {
		res += rec(M, R, n-x[M]+x[L]);
	} else {
		res += rec(L, M, n);
		res += rec(M, R, 0);
	}
	return min(res, inf);
}

pii tmp[maxn];

int main() {
	scanf("%d%d%d", &d, &n, &m);
	T.init(m+2);
	FORI(i,m) {
		scanf("%d%d", &tmp[i].fi, &tmp[i].se);
	}
	sort(tmp, tmp+m+1);
	FORI(i,m) {
		x[i] = tmp[i].fi;
		p[i] = tmp[i].se;
		T.add(i, p[i]);
	}
	x[m+1] = d;
	ll res = rec(0, m+1, n);
	if (res >= inf) cout << "-1\n";
	else cout << res << "\n";
	return 0;
}