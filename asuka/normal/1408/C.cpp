#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
#define eps 1e-8
using namespace std;
int t,n,l,a[N];
double tim[N][2],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d",&n,&l);
 		rep(i,1,n) scanf("%d",&a[i]);
 		a[n+1] = l;
 		tim[n+1][1] = 0;
 		tim[0][0] = 0;
 		rep(i,1,n+1)
 			tim[i][0] = tim[i-1][0]+(1.0*a[i]-a[i-1])/i*1.0;
 		per(i,0,n) tim[i][1] = tim[i+1][1]+(1.0*a[i+1]-a[i])/(n+1-i*1.0);
 		// rep(i,0,n+1) cout << tim[i][0] << ' ';
 		// puts("");
 		// rep(i,0,n+1) cout << tim[i][1] << ' ';
 		// puts("");
 		rep(i,1,n+1){
 			double l1,l2,r1,r2;
 			l1 = tim[i-1][0];r1 = tim[i][0];
 			l2 = tim[i][1],r2 = tim[i-1][1];
 			if(min(r1,r2)-max(l1,l2) > -eps){
 				if(tim[i][1]-tim[i-1][0] > -eps){
 					//puts("fuck");
 					double d = tim[i][1]-tim[i-1][0],len = a[i]-a[i-1];
 					len -= 1.0*d*i;
 					ans = (len)/(1.0*n+2)+tim[i][1];
 				}else{
 					//puts("Fucki"); //cout << i << endl;
 					double d = tim[i-1][0]-tim[i][1],len = a[i]-a[i-1];//cout << len << endl; 
 					len -= 1.0*d*(n-i+2);//cout << len<< endl;
 					ans = (len)/(1.0*n+2)+tim[i-1][0];
 				}
 			} 
 		}
 		printf("%.16lf\n",ans);
 	}
	return 0;
}