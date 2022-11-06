#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

struct P{
	int x,y,ix;
	P(int a,int b,int c):x(a),y(b),ix(c){}
};

bool operator<(const P &a, const P &b){
	return a.x<b.x||(a.x==b.x && a.y<b.y);
}

int main(){
	int n;
	scanf("%d",&n);
	vector<vector<P> > pnts(1100);
	rep(i,0,n){
		int xx,yy;
		scanf("%d %d",&xx,&yy);
		pnts[yy/1000].push_back(P(xx,yy,i+1));
	}
	rep(i,0,1100){
		if(i & 1)
			sort(pnts[i].rbegin(),pnts[i].rend());
		else
			sort(pnts[i].begin(),pnts[i].end());
		for(P p : pnts[i])
			printf("%d ",p.ix);
	}
	puts("");
}