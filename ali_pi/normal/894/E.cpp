#include <bits/stdc++.h>>
#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int n,m,a[N],b[N],cost[N];
vector<int> g[N],gr[N];
int used[N];
int C;
vector<int> order;

void dfs(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int id=g[v][i];
		int to=b[id];
		if (used[to])
			continue;
		dfs(to);
	}
	order.push_back(v);
}

void rdfs(int v){
	used[v]=C;
	for (int i=0;i<gr[v].size();i++){
		int id=gr[v][i];
		int to=a[id];
		if (used[to])
			continue;
		rdfs(to);
	}
}

long long COST[N];

vector<pair<int,int> > G[N];

long long dp[N];

long long subt[N],subt_sum[N];

long long get_edge_cost(long long C){

	int l,r;
	l=0;
	r=100000;
	while (l<r){
		int mid=l+r+1;
		mid/=2;
		if (subt[mid]<=C)
			l=mid;
		else
			r=mid-1;
	}
	long long res=C*l-subt_sum[l];
	return res;
}

int main(){
	subt[1]=0;
	for (int i=1;i<=100000;i++){
		subt[i+1]=subt[i]+i;
	}

	for (int i=1;i<=100000;i++){
		subt_sum[i]=subt_sum[i-1]+subt[i];
	}

	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&cost[i]);
		g[a[i]].push_back(i);
		gr[b[i]].push_back(i);
	}

	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		dfs(i);
	}

	reverse(order.begin(),order.end());
	for (int i=1;i<=n;i++){
		used[i]=0;
	}

	for (int i=0;i<order.size();i++){
		int v=order[i];
		if (used[v])
			continue;
		++C;
		rdfs(v);
	}

	for(int i=1;i<=m;i++){
		int c1=used[a[i]];
		int c2=used[b[i]];
		if (c1==c2){
			COST[c1]+=get_edge_cost(cost[i]);
		}
		else{
			G[c1].push_back(make_pair(c2,cost[i]));
		}
	}

	for (int i=C;i;--i){
		for (int j=0;j<G[i].size();j++){
			int to=G[i][j].first;
			long long res_there=dp[to]+G[i][j].second;
			dp[i]=max(dp[i],res_there);
		}
		dp[i]+=COST[i];
	}
	int start;
	cin>>start;
	start=used[start];
	cout<<dp[start]<<endl;
	return 0;
}