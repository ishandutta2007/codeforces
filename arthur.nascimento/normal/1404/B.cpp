#include <bits/stdc++.h>

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define maxn 1001000

#define mod 1000000007

#define debug 



using namespace std;

int n,a,b,da,db;
int dab, di;

vector<int> L[maxn];

int dfs(int v,int p=-1,int h=0){
	debug("dfs %d\n",v);
	if(v == b)
		dab = h;

	int r = 0;
	vector<int> vi;

	for(int i : L[v])
		if(i != p){
			int x = 1 + dfs(i,v,h+1);
			vi.pb(x);
		}

	sort(vi.begin(), vi.end());
	reverse(vi.begin(), vi.end());

	if(vi.size() == 1) r = vi[0];
	if(vi.size() > 1) r = vi[0] + vi[1];
	di = max(di,r);
	if(vi.size() == 0) return 0;
	return vi[0];
	
}

main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db), a--, b--;
		dab = di = 0;
		
		for(int i=0;i<n;i++)
			L[i].clear();

		for(int i=0;i<n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y), x--, y--;
			L[x].pb(y);
			L[y].pb(x);
		}

		dfs(a);

		if(dab <= da || db <= 2*da)
			printf("Alice\n");
		else if(di > 2*da)
			printf("Bob\n");
		else
			printf("Alice\n");

	}

}