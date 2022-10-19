#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k,x,y,z,t,flag1,flag2,ans;
char s[500039],c;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		flag1=flag2=ans=0;
		for(i=0;i<n;i++){
			c=getchar();
			while(c!='>'&&c!='<'&&c!='-') c=getchar();
			s[i]=c;
			if(s[i]=='>') flag1=1;
			if(s[i]=='<') flag2=1;
		}
		if(!flag1||!flag2) printf("%d\n",n);
		else{
			for(i=0;i<n;i++) if(s[(i-1+n)%n]=='-'||s[i]=='-') ans++;
			printf("%d\n",ans);
		}
	}
}