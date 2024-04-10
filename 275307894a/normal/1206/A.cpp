#include<cstdio>
using namespace std;
int n,m,a,maxn,minn;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a),maxn=maxn>a?maxn:a;
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&a),minn=minn>a?minn:a;
	printf("%d %d",maxn,minn);
	return 0;
}