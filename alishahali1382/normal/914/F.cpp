#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

const int MAXN=100001, LOG=20;

int n, m, k, u, v, x, y, t, l, r;
bitset<MAXN> B[26], Ans;
string S, T;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>m;
	for (int i=0; i<S.size(); i++) B[S[i]-'a'].set(i);
	
	while (m--){
		cin>>t;
		if (t==1){
			cin>>x;
			x--;
			B[S[x]-'a'].reset(x);
			cin>>S[x];
			B[S[x]-'a'].set(x);
			continue ;
		}
		cin>>l>>r>>T;
		l=l+T.size()-1;
		l--;
		r--;
		Ans=B[T[0]-'a'];
		for (int i=1; i<T.size(); i++) Ans=(Ans<<1)&B[T[i]-'a'];
//		cerr<<Ans<<'\n';
		Ans=(Ans>>l)<<(l+MAXN-1-r);
		cout<<Ans.count()<<'\n';
	}
	
	
	return 0;
}
/*
abcdabcdab
1
2 2 8 ab

*/