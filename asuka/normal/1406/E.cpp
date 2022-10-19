#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define ff fflush(stdout)
#define L 98
using namespace std;
bool notprime[N];
int n,tot,p[N],maxn,res = 1;
void init(int x){
	rep(i,2,x){
		if(!notprime[i]) p[++tot] = i;
		for(int j = 1;p[j]*i <= x&&j <= tot;++j){
			notprime[i*p[j]] = 1;
			if(i%p[j] == 0) break;
		}
	}
}
void solve(int x){
	int cur = 1,temp;
	printf("B %d\n", x);
	fflush(stdout);
	scanf("%d", &temp);
	while(1){
		cur *= x;
		if(cur > n) break;
		printf("A %d\n",cur);
		ff;
		scanf("%d",&temp);
		if(temp == 0) break;
		res *= x;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	init(n);int a;
 	rep(i,1,tot) if(1ll*p[i]*p[i] <= 1ll*n) maxn = i;
 	int sum = n;
 	rep(i,1,L){
 		int l = (i-1)*L+1,r = min(i*L,tot);
 		rep(j,l,r){
 			if(j <= maxn) continue;
 			printf("B %d\n",p[j]);
 			ff;
 			scanf("%d",&a);
 			sum -= a;
 		}
 		printf("A 1\n");
 		ff;
 		scanf("%d",&a);
 		if(a != sum){
 			rep(j,l,r){
 				if(j <= maxn) continue;
 				printf("A %d\n",p[j]);
 				ff;
 				scanf("%d",&a);
 				if(a){
 					res = p[j];
 					break;
 				}
 			}
 			break;
 		}
 		if(r == tot) break;
 	}
 	rep(i,1,maxn) solve(p[i]);

 	printf("C %d\n", res);
 	ff;
	return 0;
}