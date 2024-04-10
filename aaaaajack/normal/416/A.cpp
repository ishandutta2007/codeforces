#include<cstdio>
#define INF 1023456789
using namespace std;
int main(){
	char s[10],y;
	int n,num,low=-INF,high=INF;
	scanf("%d",&n);
	while(n--){
		scanf("%s %d %c",s,&num,&y);
		if((s[0]=='>'&&s[1]==0&&y=='Y')||(s[0]=='<'&&s[1]=='='&&y=='N')){
			if(num+1>low) low=num+1;
		}
		else if((s[0]=='<'&&s[1]==0&&y=='Y'||(s[0]=='>'&&s[1]=='='&&y=='N'))){
			if(num-1<high) high=num-1;
		}
		else if((s[0]=='>'&&s[1]=='='&&y=='Y')||(s[0]=='<'&&s[1]==0&&y=='N')){
			if(num>low) low=num;
		}
		else if((s[0]=='<'&&s[1]=='='&&y=='Y')||(s[0]=='>'&&s[1]==0&&y=='N')){
			if(num<high) high=num;
		}
	}
	if(low>high) printf("Impossible\n");
	else printf("%d\n",low);
	return 0;
}