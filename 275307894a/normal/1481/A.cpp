#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int t,n,m,k,x,y,z,now1,now2,now3,now4,flag;
char s[1000036];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);now1=now2=now3=now4=0;
		scanf("%s",s+1);k=strlen(s+1);
		for(i=1;i<=k;i++){
			if(s[i]=='U') now1++;
			else if(s[i]=='D') now2++;
			else if(s[i]=='R') now3++;
			else now4++;
		}
		if((y>0&&now1<y)||(y<0&&now2<-y)||(x>0&&now3<x)||(x<0&&now4<-x))printf("NO\n"); 
		else printf("YES\n");
	}
}