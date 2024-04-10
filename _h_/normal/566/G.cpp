#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;
typedef pair<pair<int,int>,bool> pkt;
#define mp make_pair
#define x first.first
#define y first.second
#define rep(i,a,b) for(int i = (int)(a); i < (b); ++i)
typedef long long ll;

bool cmp(const pkt& a, const pkt& b){
	return (ll)a.x*b.y < (ll)a.y*b.x;
}

bool isCW(const pkt& a, const pkt& b, const pkt& c){
	return (ll)a.x*b.y - (ll)a.y*b.x + (ll)b.x*c.y - (ll)b.y*c.x + (ll)c.x*a.y - (ll)c.y*a.x > 0;
}

int main(){
	int n,m,h,xmax=0,ymax=0,a,b;
	scanf("%d%d%d%d",&n,&m,&h,&h);
	vector<pkt> pkter(n+m+2);
	rep(i,0,n)
		scanf("%d%d",&a,&b),
		pkter[i] = mp(mp(a,b),1);
	rep(i,0,m)
		scanf("%d%d",&a,&b),
		xmax = max(xmax,a),
		ymax = max(ymax,b),
		pkter[i+n] = mp(mp(a,b),0);
	pkter[m+n] = mp(mp(xmax,0),0);
	pkter[m+n+1] = mp(mp(0,ymax),0);
	sort(pkter.begin(),pkter.end(),cmp);
	vector<pkt> holje(n+m+3);
	int ind = 1;
	holje[0] = mp(mp(0,0),0);
	for(auto p : pkter){
		if(p.x == holje[ind-1].x && p.y == holje[ind-1].y){
			holje[ind-1].second |= p.second;
			continue;
		}
		while(ind > 1 && isCW(holje[ind-2],holje[ind-1],p))
			--ind;
		holje[ind] = p;
		++ind;
	}
	//rep(i,0,ind)
	//	printf("%d %d\n",holje[i].x,holje[i].y);
	rep(i,0,ind)
		if(holje[i].second){
			printf("Max\n");
			return 0;
		}
	printf("Min\n");
}