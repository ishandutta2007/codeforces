#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
 
using namespace std;

pll T[2][3*1001000];

void update(int idx,int val,int q){
	idx++;
	while(idx < 3003000){
		T[q][idx].first += val;
		T[q][idx].second++;
		if(val < 0)
			T[q][idx].second -= 2;
		idx += idx&-idx;
	}
}

long long query(int idx,int q){
	idx++;
	long long ret = 0;
	while(idx){
		ret += T[q][idx].first;
		idx -= idx&-idx;
	}
	return ret;
}

long long search(int qnt, int q){

	long long ret = 0;
	int pos = 0;

	for(int i=19;i>=0;i--)///////////////////////////////////////
		if(T[q][pos+(1<<i)].second <= qnt)
			pos += (1<<i),
			qnt -= T[q][pos].second,
			ret += T[q][pos].first;

	return ret;
}

struct y {
	int a,b,idx;
	bool operator < (y comp)const {
		return a + comp.b < b + comp.a;}
};

y v[300300];

int comp1[300300];
int comp2[300300];

long long best = (1LL<<50);
long long q2 = 0;
int quebra = 0;

int n,w;


long long F(int qnt2){

	int qnt1 = w - 2*qnt2;
	if(qnt1 < 0) qnt1 = 0;

	long long ret = search(qnt1,0) + search(qnt2,1);
	
	debug("F %d %d = %I64d\n",qnt1,qnt2,ret);

	return ret;

}

int ans[300300];

void testa(int qq){

	debug("testa qq = %d\n",qq);
	long long cur = 0;

	int ma = qq+1;
	int mb = n-qq-1;

	int b = min(mb,(w+1)/2);

	int a = max((w-ma+1)/2,0);
	debug("%d~%d\n",a,b);

	if(ma + 2*mb < w)
		return;

	while(a-b){
		//debug("a = %d b = %d\n",a,b);
		if(b-a <= 4){
			int u = a;
			long long bb = (1LL<<50);
			for(int i=a;i<=b;i++)
				if(F(i) < bb)
					bb = F(i), u= i;
			a = b = u;
			continue;
		}
		int mid = (a+b+1)/2;
		if(F(mid-1) < F(mid))
			b = mid;
		else
			a = mid-1;
	}

	cur = F(a);

	debug("qq = %d cur = %I64d\n",qq,cur);

	if(cur < best){
		best = cur;
		q2 = a;
		quebra = qq;
	}

}


main(){

		scanf("%d%d",&n,&w);

		for(int i=0;i<n;i++)
			scanf("%d%d",&v[i].a,&v[i].b), v[i].idx = i;

		sort(v,v+n);

		vector<pii> u1;
		vector<pii> u2;
		for(int i=0;i<n;i++)
			u1.pb(pii(v[i].a,i)),
			u2.pb(pii(v[i].b,i));
		sort(u1.begin(), u1.end());
		sort(u2.begin(), u2.end());

		for(int i=0;i<n;i++)
			comp1[u1[i].second] = i;
		for(int i=0;i<n;i++)
			comp2[u2[i].second] = i;

		for(int i=0;i<n;i++)
			update(comp2[i], v[i].b, 1);

		testa(-1);

		for(int i=0;i<n;i++){
			update(comp2[i], -v[i].b, 1);
			debug("erase %d\n",v[i].b);
			update(comp1[i], v[i].a, 0);
			debug("insert %d\n",v[i].a);
			testa(i);
		}

		printf("%I64d\n",best);

		vector<pii> va, vb;

		for(int i=0;i<=quebra;i++)
			va.pb(pii(v[i].a,v[i].idx));
		for(int i=quebra+1;i<n;i++)
			vb.pb(pii(v[i].b,v[i].idx));
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		debug("ok");
		int Q2 = q2;
		int Q1 = w-2*Q2;
		debug("quebra = %d Q1 = %d Q2 = %d\n",quebra,Q1,Q2);
		for(int i=0;i<Q1;i++)
			ans[va[i].second] = 1;
		for(int i=0;i<Q2;i++)
			ans[vb[i].second] = 2;
		for(int i=0;i<n;i++)
			printf("%d",ans[i]);
		printf("\n");

}