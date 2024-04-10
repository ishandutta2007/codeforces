#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,sx,sy;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d",&sx,&sy);
	printf("%d %d\n",sx,sy);
	int lst = n;
	rep(i,1,m) if(i != sy) printf("%d %d\n",sx,i); lst = n;
	rep(i,1,n){
		if(i == sx) continue;
		if(lst == n){
			per(j,1,m) printf("%d %d\n",i,j);
			lst = 1;
		}else{
			rep(j,1,m) printf("%d %d\n",i,j);
			lst = n;
		}
	}
	return 0;
}