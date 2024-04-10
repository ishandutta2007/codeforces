#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,ans,tot,pus,flag;
struct yyy{
	int x,y;
}s[1039];
inline bool cmp(yyy a,yyy b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&s[i].x,&s[i].y);
		sort(s+1,s+n+1,cmp);
		for(i=2;i<=n;i++) if(s[i].y<s[i-1].y) {flag=1;break;}
		if(flag) printf("NO\n");
		else{
			printf("YES\n");
			for(i=1;i<=n;i++){
				for(j=1;j<=s[i].x-s[i-1].x;j++) putchar('R');
				for(j=1;j<=s[i].y-s[i-1].y;j++) putchar('U');
			}
			printf("\n");
		}
	}
	return 0;
}