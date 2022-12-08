#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int MN = 1e6 + 10;

int n , k , fen[MN];
vector<int>adj[MN];
int par[MN] , st[MN] , ft[MN] , Time , h[MN];
bool mk[MN];

void dfs(int s,int pr){
	st[s] = Time++;
	par[s] = pr;
	for(auto v:adj[s]) if(v^pr){
		h[v] = h[s] + 1;
		dfs(v , s);
	}
	ft[s] = Time;
}

void add(int p,int val){
	for(;p;p-=p&-p) fen[p] += val;
}

int get(int p){
	int ret = 0;
	for(p++;p<MN;p+=p&-p) ret += fen[p];
	return ret;
}

int main(){
	ios :: sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	cin >> n >> k;
	k = n-k;
	for(int i=1;i<n;++i){
		int a,b;cin>>a>>b;--a,--b;
		adj[a].pb(b) , adj[b].pb(a);
	}
	
	dfs(n-1 , -1);
	int cur_sz = 1;
	mk[n-1] = true;
	for(int i=n-2;~i;i--){
		int t = get(st[i]);
		if(cur_sz + h[i] - t <= k){
			int cur = i;
			while(!mk[cur]){
				add(ft[cur] , 1);
				add(st[cur] , -1);
				mk[cur] = true;
				cur = par[cur];
				cur_sz++;
			}
		}
	}
	for(int i=0;i<n;i++) if(!mk[i]) cout << i+1 << ' ';
	cout << '\n';
	return 0;
}