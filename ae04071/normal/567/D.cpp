#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,k,a,m;
struct td{
	int l,r,val;
	td() {}
	td(int l,int r,int val):l(l),r(r),val(val){}
	bool operator<(const td &rhs)const {
		return l!=rhs.l ? l<rhs.l : r<rhs.r;
	}
};
int get(int s) {
	int val = s/(a+1);
	if(s-val*(a+1)==a) val++;
	return val;
}
int main() {
	scanf("%d%d%d%d",&n,&k,&a,&m);
	set<td> tr;
	tr.insert(td(1,n,get(n)));
	int i=0,s=get(n);
	for(;i<n;i++) {
		int p;
		scanf("%d",&p);
		auto it=tr.upper_bound(td(p,n+1,0));
		
		if(it==tr.begin()) continue;

		it--;
		if(it->r < p) continue;

		s -= it->val;

		int lv=get(p-it->l), rv=get(it->r-p);
		s += lv+rv;

		if(lv > 0) tr.insert(td(it->l,p-1, lv));
		if(rv > 0) tr.insert(td(p+1,it->r, rv));
		tr.erase(it);
		if(s < k) break;
	}
	if(i==n) puts("-1");
	else printf("%d ",i+1);
	return 0;
}