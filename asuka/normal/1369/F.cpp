#include<bits/stdc++.h>
#define int long long
#define N 1000015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int win(int e,int s){
	if(s == e) return 0;
	if(s+1 == e) return 1;
	if(e&1) return !(s&1);
	if(s <= e/4) return win(e/4,s);
	if(s <= e/2) return 1;
	return (e-s)&1;
}
int lose(int e,int s){
	if((s<<1) > e) return 1;
	return win(e/2,s);
}
int n,a,b,w[N],l[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n) {
		scanf("%lld%lld",&a,&b);
		w[i] = win(b,a); l[i] = lose(b,a);
	}
	a = w[n];
	per(i,1,n-1){
		if(a) {if(!l[i]) a ^= 1;}
		else if(w[i]) a ^= 1;
	}
	printf("%lld ",a);
	a = l[n];
	per(i,1,n-1){
		if(a){if(!l[i]) a ^= 1;}
		else if(w[i]) a ^= 1;
	}
	printf("%lld\n",a);
	return 0;
}