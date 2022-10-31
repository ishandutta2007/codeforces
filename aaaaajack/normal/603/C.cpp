#include<cstdio>
using namespace std;
int main(){
	int n,k,x,ans=0;
	scanf("%d%d",&n,&k);
	int sg[10]={};
	sg[0]=0;
	for(int i=1;i<10;i++){
		bool u[3]={};
		u[sg[i-1]]=true;
		if(!(i&1)){
			if(k&1) u[sg[i>>1]]=true;
			else u[0]=true;
		}
		while(u[sg[i]]) sg[i]++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x<10) ans^=sg[x];
		else{
			if(k&1){
				if(!(x&1)){
					int c=0,t;
					while(x>=10&&!(x&1)) x>>=1,c++;
					if(x<10) t=sg[x];
					else t=0;
					while(c--){
						if(t==1) t=2;
						else t=1;
					}
					ans^=t;
				}					
			}
			else{
				ans^=(x+1)&1;
			}
		}
	}
	if(ans) puts("Kevin");
	else puts("Nicky");
	return 0;
}