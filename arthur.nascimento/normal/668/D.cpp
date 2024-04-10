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
#define maxn 1001000
#define max3(a,b,c) max(max(a,b),c)

typedef long long ll;
using namespace std;

int T[maxn];
void update(int idx,int val){
	idx++;
	while(idx < maxn){
		T[idx] += val;
		idx += idx&-idx;
	}
}
int sum(int idx){
	idx++;
	int ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}

struct bla {
	int num, beg, cur, tipo, t, idx;
}

v[maxn];

bool cmp(bla a,bla b){
	if(a.num != b.num)
		return a.num < b.num;
	return a.t < b.t;
}

bool cmp2(bla a,bla b){
	return a.idx < b.idx;
}

char ch;
int rt;
inline int read(){
	rt = 0;
	while((ch=getchar()) >= '0')
		rt = 10*rt+ch-'0';
	return rt;
}

main(){

	int n = read();
	for(int i=0;i<n;i++){
		v[i].tipo = read();
		v[i].t = read();
		v[i].num = read();
		v[i].idx = i;
	}


	sort(v,v+n,cmp);

	int u = 0, cara = v[0].num;

	for(int i=0;i<n;i++){
		if(v[i].num != cara){
			cara = v[i].num;
			u = i;
		}
		v[i].beg = u;
		v[i].cur = i;
	}

	sort(v,v+n,cmp2);

	for(int i=0;i<n;i++){

		//debug("query num %d tipo %d cur %d beg %d\n",v[i].num,v[i].tipo,v[i].cur,v[i].beg);

		if(v[i].tipo == 1)
			update(v[i].cur,1);
		if(v[i].tipo == 2)
			update(v[i].cur,-1);
		if(v[i].tipo == 3)
			printf("%d\n",sum(v[i].cur)-sum(v[i].beg-1));

	}

}