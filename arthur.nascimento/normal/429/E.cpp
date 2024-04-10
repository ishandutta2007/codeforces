#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

typedef long long ll;
using namespace std;

struct seg {
	int l,r,f,idx;
	seg(int l=0,int r=0,int f=0,int idx=0): l(l), r(r), f(f), idx(idx) {}
	bool operator<(seg comp)const{
		if(r == comp.r){
			if(f != comp.f)
				return f;
			return idx < comp.idx;
		}
		return r > comp.r;
	}
};

set<seg> S;
int qnt;

int ans[maxn];

void go(){

	if(S.size() == 0)
		return;
	if(S.size() == 1){
		ans[(S.begin())->idx] = 1;
		return;
	}

	seg a = *(S.begin());
	S.erase(a);

	seg b = *(S.begin());

	if(b.r < a.l || (b.r == a.l && !b.f)){
		ans[a.idx] = 1;
		go();
		return;
	}

	S.erase(b);

	if(b.l == a.l){
		ans[a.idx] = 1;
		ans[b.idx] = -1;
		go();
		return;
	}

	int u = qnt;
	seg c (min(b.l,a.l),max(b.l,a.l),0,u);
	qnt++;
	
	S.insert(c);

	go();

	if(a.l < b.l){
		ans[a.idx] = ans[c.idx];
		ans[b.idx] = -ans[c.idx];
	}
	else {
		ans[a.idx] = -ans[c.idx];
		ans[b.idx] = ans[c.idx];
	}
	
}

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		seg a;
		scanf("%d%d",&a.l,&a.r);
		a.idx = i;
		a.f = 1;
		S.insert(a);
	}

	qnt = n;
	go();

	for(int i=0;i<n;i++)
		printf("%d ",(ans[i]+1)/2);
	printf("\n");
}