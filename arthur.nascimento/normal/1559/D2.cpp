#include <bits/stdc++.h>

#define maxn 100100

#define ll long long

#define debug

#define pb push_back

#define pii pair<int,int>
#define mid ((ini+fim)/2)

using namespace std;

int par[2][maxn];

int find(int t,int x){
	return par[t][x] = (x == par[t][x]) ? x : find(t,par[t][x]);
}

void join(int t,int a,int b){
	debug("join %d %d\n",a,b);
	par[t][find(t,a)] = find(t,b);
}

main(){

	int n,m[2];
	scanf("%d%d%d",&n,m,m+1);

	for(int i=1;i<=n;i++)
		par[0][i] = par[1][i] = i;

	for(int i=0;i<2;i++)
		for(int j=0;j<m[i];j++){
			int a,b;
			scanf("%d%d",&a,&b);
			par[i][find(i,a)] = find(i,b);
		}

	vector<pii> ans;

	int p[2] = {1,1};

	while(1){

		for(int i=0;i<2;i++)
			while(p[i] < n && find(i,p[i]) == find(i,p[i]+1)) p[i]++;

		int A = p[0], B = p[0]+1, C = p[1], D = p[1] + 1;
		
		if(A == n || C == n) break;

		if(find(0,C) != find(0,D)){
			ans.pb({C,D});
			join(0,C,D);
			join(1,C,D);
		}
		else {
			if(find(0,A) == find(0,C)) swap(A,B);
			if(find(1,A) == find(1,C)) swap(C,D);
			ans.pb({A,C});
			join(0,A,C);
			join(1,A,C);
		}

	}

	printf("%d\n",ans.size());
	for(pii i : ans)
		printf("%d %d\n",i.first,i.second);

}