#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,t,h[1000039],flag,flags;
char s[1000039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		cin>>s+1;
		n=strlen(s+1);
		scanf("%d",&x);flags=0;
		for(i=1;i<=n;i++) h[i]=1;
		for(i=1;i<=n;i++){
			if(s[i]=='0'){
				if(i+x<=n)h[i+x]=0;
				if(i-x>=1) h[i-x]=0;
			} 
		} 
		for(i=1;i<=n;i++){
			if(s[i]=='1'){
				flag=0;
				if(i+x<=n) flag|=h[i+x];
				if(i-x>=1) flag|=h[i-x];
				if(!flag) {flags=1;break;}
			}
		}
		if(flags)printf("-1\n");
		else{
			for(i=1;i<=n;i++) printf("%d",h[i]);
			printf("\n");
		}
	}
}