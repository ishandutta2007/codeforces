#include<cstdio>
using namespace std;
int main(){
	int i,cnt=0,n,x1,y1,x2,y2;
	long long a,b,c;
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		if((a*x1+b*y1+c<0)^(a*x2+b*y2+c<0)) cnt++;
	}
	printf("%d\n",cnt);
}