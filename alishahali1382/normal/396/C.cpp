#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int MAXN = 300010;

int n, m, k, u, v, x, y, t, a, b, type;
ll H[MAXN];
ll BIT1[MAXN], BIT2[MAXN];
int st[MAXN], fn[MAXN], timer=1;
vector<int> child[MAXN];

void upd(ll BIT[], int id, ll x){
	for (; id<MAXN; id+=id&(-id)) BIT[id]=(BIT[id]+x)%mod;
}

ll get(ll BIT[], int id){
	ll res=0;
	for (; id; id-=id&(-id)) res=(res+BIT[id])%mod;
	return res;
}

void dfs(int node){
	st[node]=timer++;
	for (int v:child[node]) H[v]=H[node]+1, dfs(v);
	fn[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=2; i<=n; i++) cin>>x, child[x].push_back(i);
	dfs(1);
	cin>>m;
	while (m--){
		cin>>type>>v;
		if (type==2) cout<<((get(BIT1, st[v])-H[v]*get(BIT2, st[v]))%mod+mod)%mod<<'\n';
		else{
			cin>>x>>k;
			upd(BIT1, st[v], x+k*H[v]);
			upd(BIT1, fn[v], -(x+k*H[v]));
			upd(BIT2, st[v], k);
			upd(BIT2, fn[v], -k);
		}
	}
	
	return 0;
}