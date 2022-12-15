#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

#define sz(x) ((int)x.size())
#define fi first
#define se second

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

struct data{
	int l,r,h,w;
	data() {}
	data(int l,int r,int h,int w):l(l),r(r),h(h),w(w) {}
	bool operator<(const data &rhs)const {
		return l!=rhs.l ? l<rhs.l : r<rhs.r;
	}
};
set<data> tr;

set<pii> chk;

int n,m;

int proc(int x,int y,char ch) {
	auto it=tr.upper_bound(data(x,n+1,0,0));
	it--;
	
	int res;
	if(ch=='L') res=x - it->w;
	else res = y - it->h;
	
	int l=it->l, r=it->r, w=it->w, h=it->h;
	tr.erase(it);

	if(ch=='L') {
		if(l<x) tr.insert(data(l,x-1,y,w));
		tr.insert(data(x,r,h,w));
	} else {
		tr.insert(data(l,x,h,w));
		if(x<r) tr.insert(data(x+1,r,h,x));
	}
	return res;
}
int main() {
	scanf("%d%d",&n,&m);
	tr.insert(data(1,n,0,0));

	for(int i=0;i<m;i++) {
		int x,y;
		char ch;
		
		scanf("%d%d %c",&x,&y,&ch);
		if(chk.find(pii(x,y))!=chk.end()) {
			puts("0");
			continue;
		}
		chk.insert(pii(x,y));
		printf("%d\n",proc(x,y,ch));
	}

	return 0;
}