#include<bits/stdc++.h>
#define ll long long
#define N 2005
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
int t,n,p1,p2;
bool gkp[N];
bool check(int x){
	printf("? %d %d\n",x,p2-x);
	rep(i,1,x) printf("%d ",i); puts("");
	rep(i,x+1,p2) printf("%d ",i); puts("");
	fflush(stdout);
	int tmp; scanf("%d",&tmp);
	if(tmp) return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		rep(i,1,n) gkp[i] = 0; p1 = p2 = 0;
 		rep(i,2,n){
 			printf("? %d %d\n",i-1,1);
 			rep(j,1,i-1) printf("%d ",j); puts("");
 			printf("%d\n",i); fflush(stdout);
 			scanf("%d",&p2);
 			if(p2 == 0) continue; p2 = i;
 			int l = 1,r = p2-1,ans = 0;
 			while(l <= r){
 				int mid = (l+r)>>1;
 				if(check(mid)) ans = mid,r = mid-1;
 				else l = mid+1;
 			}
 			p1 = ans;
 			rep(j,1,p2) if(j!=p1&&j!=p2) gkp[j] = 1;
 			int pre = -114;
 			rep(j,p2+1,n){
 				printf("? 1 %d\n",j-p2);
 				printf("%d\n",p2);
 				rep(k,p2+1,j) printf("%d ",k); puts("");
 				fflush(stdout);
 				int tmp; scanf("%d",&tmp);
 				if(pre == -114){if(tmp == 0) gkp[j] = 1;}
 				else if(tmp == pre) gkp[j] = 1;
 				pre = tmp;
 			}
 			int cnt = 0;
 			rep(j,1,n) cnt += gkp[j];
 			printf("! %d ",cnt);
 			rep(j,1,n) if(gkp[j]) printf("%d ",j);
 			puts("");
 			fflush(stdout);
 			break;
 		}
 	}
	return 0;
}