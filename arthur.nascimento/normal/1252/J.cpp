#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
typedef int num;
#define par pair<num,num>
#define point pair<par,int>
#define debug 
#define inf 2e9
#define X first.first
#define Y first.second
#define pb push_back
#define prev(x) (x-1)
#define ll long long

struct paretto {

	set<point> S;
	set<point> :: iterator it, aux;
	num INF, NINF;
	ll area;
	
	void add(point a,point b){
		//printf("add (%d;%d) ~ (%d;%d)\n",a.X,a.Y,b.X,b.Y);
		if(a.second+1) area -= (ll) a.Y * (b.X - a.X);
	}
	
	void rem(point a,point b){
		//printf("rem (%d;%d) ~ (%d;%d)\n",a.X,a.Y,b.X,b.Y);
		if(a.second+1) area += (ll) a.Y * (b.X - a.X);
	}
	
	paretto(int n){
		INF = inf;
		NINF = -inf;
		area = 0;
		point a (par(NINF,INF),-1);
		point b (par(n+1,NINF),-1);
		S.insert(a);
		S.insert(b);
		add(a,b);
	}
	
	point qry(num x){
		it = S.lower_bound(point(par(x,INF),-1));
		return *(--it);
	}
	
	void insert(num x,num y,int id){
	
		point lo = qry(x);
		if(lo.Y <= y) return;
		point P (par(x,y),id);
		S.insert(P);
		aux = it = S.find(P);
		it++;
		aux--;
		rem(*aux,*it);
		add(*aux,P);
		
		while(1){
			it = S.find(P); it++;
			if(it->Y < y) break;
			aux = it; aux++;
			rem(*it,*aux);
			S.erase(it);
		}
		
		it = S.find(P); it++;
		add(P,*it);
	}

};



#define maxn 200200
int v[maxn];
int oc[4][maxn];
vector<pii> L[maxn];

main(){

	int n;
	scanf("%d",&n);
	memset(oc,-1,sizeof(oc));
	for(int i=0;i<maxn;i++) oc[0][i] = oc[2][i] = n;
	for(int i=0;i<n;i++){
		scanf("%d",v+i);
		if(oc[0][v[i]] == n) oc[0][v[i]] = i;
		else if(oc[2][v[i]] == n) oc[2][v[i]] = i;
	}
	for(int i=n-1;i>=0;i--){
		if(oc[1][v[i]] == -1) oc[1][v[i]] = i;
		else if(oc[3][v[i]] == -1) oc[3][v[i]] = i;	
	}
		
	//oc[0][1] = -1, oc[1][1] = n;
		
	for(int x=1;x<maxn;x++){
		int a = n, b = -1;
		int o2 = n, o3 = -1;
		for(int j=x;j<maxn;j+=x){
			if(oc[0][j] >= a)
				o2 = min(o2,oc[0][j]);
			else o2 = a;
			
			if(oc[1][j] <= b)
				o3 = max(o3, oc[1][j]);
			else o3 = b;
			
			a = min(a,oc[0][j]), b = max(b,oc[1][j]);
			
		}
		
		if(a >= b) continue;
		debug("x %d vals %d %d %d %d\n",x,a,o2,o3,b);		
		if(a < b)
			L[b].pb(pii(a,x));
		if(o2 < n)
			L[n].pb(pii(o2,x));
		if(o3+1)
			L[o3].pb(pii(-1,x));
	}
	
	paretto P(n);
	
	ll ans = 0;
	for(int i=n;i>=1;i--){
		debug("i %d\n",i);
		P.insert(i-1,-maxn,-1);
		for(int j=0;j<L[i].size();j++){
			int val = L[i][j].second, id = L[i][j].first;
			P.insert(id,-val,i);
			debug("add %d;%d\n",id,val);
			
			
		}
		ans += P.area;	
		debug("area %lld\n",P.area);
	
	}
	
	printf("%lld\n",ans);
}