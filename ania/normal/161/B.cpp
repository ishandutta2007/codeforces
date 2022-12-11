#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
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

#define maxn 1001

int c[maxn], t[maxn];
vector<pair<int,int> > st, pe;
vector<int> C[maxn];

int main()
{
	int n,k;
	long long sum_disc = 0, sum = 0;
	scanf("%d%d", &n, &k);
	FOR(i,n) scanf("%d%d", &c[i], &t[i]);
	FOR(i,n)
	{
		if(t[i] == 1)
			st.pb(mp(c[i], i));
		else
			pe.pb(mp(c[i], i));
		sum += c[i];
	}
	sort(st.begin(), st.end());
	sort(pe.begin(), pe.end());
	int S = st.size(), P = pe.size();
	if(S < k)
	{
		FOR(i,S)
		{
			sum_disc += st[i].fi;
			C[i].pb(st[i].se);
		}
		S--;
		FOR(i,P)
		{
			if(S+1 < k) S++;
			C[S].pb(pe[i].se);
		}
	}
	else
	{
		int pos = S - k;
		for(int i = 1; i < k; i++)
		{
			sum_disc += st[pos+i].fi;
			C[i].pb(st[i+pos].se);
		}
		for(int i = 0; i <= pos; i++)
		{
			C[0].pb(st[i].se);
		}
		FOR(i,P)
		{
			C[0].pb(pe[i].se);
		}
		int ch = st[0].fi;
		if(pe.size() > 0) ch = min(st[0].fi, pe[0].fi);
		sum_disc += ch;
	}
	long long pr = sum * 2 - sum_disc;
	cout << pr / 2 << "." << 5 * (pr%2) << endl;
	FOR(i,k)
	{
		cout << C[i].size();
		FOREACH(j,C[i]) cout << " " << *j+1;
		cout << endl;
	}
	return 0;
}