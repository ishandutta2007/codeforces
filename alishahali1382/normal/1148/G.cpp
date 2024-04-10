#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

const int MAXN=100010, MAXA=10000001;

int n, m, k, u, v, x, y, t, a, b, good;
int A[MAXN];
int sieve[MAXA], cnt[MAXA], P[8], mul[1<<8], ted;
int dwn[MAXN], up[MAXN];
bool mark[MAXN];
vector<int> Q[MAXN];

inline void taj(int x){
	ted=0;
	while (x>1){
		int p=sieve[x];
		while (x%p==0) x/=p;
		for (int mask=0; mask<(1<<ted); mask++) mul[mask|(1<<ted)]=mul[mask]*p;
		P[ted++]=p;
	}
}
inline void add(int x, int w=+1){
	taj(x);
	for (int i=0; i<(1<<ted); i++) cnt[mul[i]]+=w;
}
inline int get(int x){
	int res=0;
	taj(x);
	for (int i=0; i<(1<<ted); i++){
		if (__builtin_popcount(i)&1) res-=cnt[mul[i]];
		else res+=cnt[mul[i]];
	}
	return res;
}
inline void clr(){
	memset(cnt, 0, sizeof(cnt));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXA; i++) if (!sieve[i]) for (int j=i; j<MAXA; j+=i) sieve[j]=i;
	mul[0]=1;
	cin>>n>>k;
	n=2*k;
	for (int i=1; i<=n; i++) cin>>A[i], add(A[i]), up[i]=n+1;;
	for (int i=1; i<=n; i++){
		int tmp=get(A[i]);
		if (!tmp) mark[i]=1, t++;
		if (tmp>=2) good=i;
	}
	clr();
	if (!good){
		for (int i=1; i<=n && k; i++) if (!get(A[i])){
			add(A[i]);
			k--;
			cout<<i<<' ';
		}
		cout<<'\n';
		return 0;
	}
	if (t>=k){
		for (int i=1; i<=n && k; i++) if (mark[i]) cout<<i<<' ', k--;
		cout<<'\n';
		return 0;
	}
	mark[good]=1;
	for (int i=1; i<=n; i++) if (__gcd(A[i], A[good])==1){
		mark[i]=1;
		break ;
	}
	
	while (1){
		int done=1;
		for (int i=1; i<=n; i++) Q[i].clear();
		for (int i=1; i<=n; i++) if (up[i]-dwn[i]>1){
			done=0;
			int mid=(dwn[i]+up[i])>>1;
			Q[mid].push_back(i);
		}
		if (done) break ;
		clr();
		for (int i=1; i<=n; i++){
			add(A[i]);
			for (int j:Q[i]){
				if (get(A[j])) up[j]=i;
				else dwn[j]=i; 
			}
		}
	}
	
	cout<<good<<' ';
	k--;
	for (int i=1; i<=n; i++) if (!mark[i]){
		if (mark[up[i]] && k>=2){
			cout<<i<<' ';
			mark[i]=1;
			k--;
		}
		if (!mark[up[i]] && k>=3){
			cout<<i<<' '<<up[i]<<' ';
			mark[i]=mark[up[i]]=1;
			k-=2;
		}
	}
	for (int i=1; i<=n && k; i++) if (__gcd(A[good], A[i])==1) cout<<i<<' ', k--;
	cout<<'\n';
	
	return 0;
}