#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int main(){
	int a,b,i,j,k;
	long long ans,temp;
	int chs=0;
	scanf("%d%d",&a,&b);
	ans=1LL*a*a-1LL*b*b;
	for(i=1;i<=min(a,b);i++){
		temp=1LL*(a-i+1)*(a-i+1)+i-1-1LL*i*(b/i)*(b/i)-1LL*(2*(b/i)+1)*(b%i);
		if(temp>ans){
			ans=temp;
			j=i;
			chs=1;
		}
	}
	for(i=1;i<=min(a,b-1);i++){
		temp=1LL*(a-i+1)*(a-i+1)+i-1-1LL*(i+1)*(b/(i+1))*(b/(i+1))-1LL*(2*(b/(i+1))+1)*(b%(i+1));
		if(temp>ans){
			ans=temp;
			k=i;
			chs=2;
		}
	}
	printf("%I64d\n",ans);
	//printf("%d\n",chs);
	if(chs==0){
		for(i=0;i<a;i++) putchar('o');
		for(i=0;i<b;i++) putchar('x');
		putchar('\n');
	}
	else if(chs==1){
		for(i=0;i<j;i++){
			if(i) putchar('o');
			else{
				for(k=0;k<a-j+1;k++) putchar('o');
			}
			if(i<b%j) putchar('x');
			for(k=0;k<b/j;k++) putchar('x');
		}
		putchar('\n');
	}
	else{
		for(j=0;j<b/(k+1);j++) putchar('x');
		for(i=0;i<k;i++){
			if(i) putchar('o');
			else{
				for(j=0;j<a-k+1;j++) putchar('o');
			}
			if(i<b%(k+1)) putchar('x');
			for(j=0;j<b/(k+1);j++) putchar('x');
		}
		putchar('\n');
	}
	return 0;
}