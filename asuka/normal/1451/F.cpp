#include<bits/stdc++.h>
#define ll long long
#define N 105
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
int t,n,m,Xor[205];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m); int x;
		memset(Xor,0,sizeof Xor);
		rep(i,1,n) rep(j,1,m){
			scanf("%d",&x);
			Xor[i+j] ^= x;
		}
		if(*max_element(Xor+2,Xor+n+m+1)==0) puts("Jeel");
		else puts("Ashish");
	}
	return 0;
}