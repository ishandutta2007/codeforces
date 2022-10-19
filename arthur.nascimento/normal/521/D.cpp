#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 99999999999999999LL
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

long long v0[maxn];
int tipo[maxn];
int c[maxn];
int cara[maxn];

int bestset[maxn];

struct skill {
	int idx;
	long double val;
	skill(int idx=0,long double val=0): idx(idx), val(val) {}
	bool operator<(skill comp)const{
		return val < comp.val;
	}
};

long double pprod[maxn];
long double psum[maxn];

int lista[maxn];


vector<pii> v[maxn];
int cade[maxn];

bool cmp(int a,int b){
	return tipo[a] < tipo[b];
}

main(){

	int n,m,k;
	scanf("%d%d%d",&m,&n,&k);

	for(int i=0;i<m;i++)
		scanf("%I64d",v0+i);

	memset(bestset,-1,sizeof(bestset));

	for(int i=0;i<n;i++){
		scanf("%d%d%d",tipo+i,cara+i,c+i), cara[i]--;
		if(tipo[i] == 1)
			if(bestset[cara[i]] == -1 || c[bestset[cara[i]]] < c[i])
				bestset[cara[i]] = i;
	}

	for(int i=0;i<n;i++)
		if(tipo[i] == 2)
			v[cara[i]].pb(pii(c[i],i));

	for(int i=0;i<m;i++)
		if(bestset[i] != -1 && c[bestset[i]] > v0[i]){
			v[i].pb(pii(c[bestset[i]]-v0[i],bestset[i]));
			debug("add %d\n",bestset[i]);
		}

	for(int i=0;i<m;i++){
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
	}
	
	vector<pii> pi;

	for(int i=0;i<n;i++)
		if(tipo[i] == 3)
			pi.pb(pii(c[i],i));
			
	sort(pi.begin(),pi.end());
	reverse(pi.begin(),pi.end());

	if(pi.size())
		pprod[0] = log(pi[0].first);
	for(int i=1;i<pi.size();i++)
		pprod[i] = pprod[i-1] + log(pi[i].first);

	priority_queue<skill> Q;
	for(int i=0;i<m;i++)
		if(v[i].size()){
			Q.push(skill(v[i][0].second,log(v0[i]+v[i][0].first)-log(v0[i])));
			debug("++ %d vr = %lf\n",v[i][0].second,(double)(v0[i]+v[i][0].first)/(v0[i]));
			cade[i]++;
			v0[i] += v[i][0].first;
		}

	int len = 0;
	while(Q.size()){
		skill u = Q.top();
		Q.pop();
		lista[len] = u.idx;
		debug("+ %lf\n",(double)u.val);
		psum[len] = u.val;
		if(len) psum[len] += psum[len-1];
		len++;
		if(cade[cara[u.idx]] != v[cara[u.idx]].size()){
			int r = cara[u.idx];
			int p = cade[r];
			Q.push(skill(v[r][p].second,log(v0[r]+v[r][p].first)-log(v0[r])));
			debug("++ %d vr = %lf\n",v[r][p].second,(double)(v0[r]+v[r][p].first)/(v0[r]));
			cade[r]++;
			v0[r] += v[r][p].first;
		}
	}

	debug("ps %d pi %d\n",len,pi.size());

	debug("sum: ");
	for(int i=0;i<len;i++)
		debug("%d ",lista[i]);
	debug("\nprod: ");
	for(int i=0;i<pi.size();i++)
		debug("%d ",pi[i].second);
	debug("\n");

	long double ans = 0;
	int ps=-1, pp=-1;
	for(int i=0;i<=min(k,len);i++){
		if(i > len) continue;
		long double cur = 0;
		if(i) cur += psum[i-1];
		int r = k - i;
		if(r > pi.size())
			r = pi.size();
		if(r)
			cur += pprod[r-1];
		debug("cur %lf\n",(double)cur);
		if(cur > ans){
			ans = cur;
			ps = i;
			pp = r;
		}
	}

	vector<int> bld;

	for(int i=0;i<ps;i++)
		bld.pb(lista[i]);
	for(int i=0;i<pp;i++)
		bld.pb(pi[i].second);

	sort(bld.begin(),bld.end(),cmp);

	printf("%d\n",bld.size());
	for(int i=0;i<bld.size();i++)
		printf("%d\n",1+bld[i]);

}