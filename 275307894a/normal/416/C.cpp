#include<cstdio>
#include<algorithm>
using namespace std;
struct yyy{int x,y,num;}s[100039];
struct ques{int x,num;}f[100039];
inline bool cmp1(ques x,ques y){return x.x<y.x;}
inline bool cmp(yyy x,yyy y){return x.y>y.y;}
int n,m,k,x,y,z,flag[100039],ans,xs[100039],ys[100039],tots;
int main(){
//	freopen("booking.in","r",stdin);
//	freopen("booking.out","w",stdout);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&s[i].x,&s[i].y),s[i].num=i;
	sort(s+1,s+n+1,cmp);
	scanf("%d",&m);
	for(i=1;i<=m;i++) scanf("%d",&f[i].x),f[i].num=i;
	sort(f+1,f+m+1,cmp1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!flag[j]&&s[i].x<=f[j].x){flag[j]=1;ans+=s[i].y;xs[++tots]=s[i].num,ys[tots]=f[j].num;break;}
		}
	}
	printf("%d %d\n",tots,ans);
	for(i=1;i<=tots;i++) printf("%d %d\n",xs[i],ys[i]);
}