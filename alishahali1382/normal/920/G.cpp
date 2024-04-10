#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
using namespace std;

const int MAXN = 1000010;

int n, p, k, u, v, x, y, t, a, b, ans;
short mob[MAXN];
vector<int> D[MAXN];

int f(int x, int p){
	int res=0;
	for (int d:D[p]) res+=(x/d)*mob[d];
	return res;
}

void solve(){
	cin>>x>>p>>k;
	k+=f(x, p);
	int dwn=0, up=7e6;
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (f(mid, p)>=k) up=mid;
		else dwn=mid;
	}
	cout<<up<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	mob[1]=1;
	for (int i=1; i<MAXN; i++) if (mob[i]) for (int j=i+i; j<MAXN; j+=i) mob[j]-=mob[i];
	for (int i=1; i<MAXN; i++) if (mob[i]) for (int j=i; j<MAXN; j+=i) D[j].push_back(i);
	int T;cin>>T;
	while (T--) solve();
	
	return 0;
}