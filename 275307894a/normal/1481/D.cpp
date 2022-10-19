#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,x,y,z,t,f[1039][1039],g[1039][1039],flag,now1,now2;
char _s;
int main(){
	//freopen("1.in","r",stdin);
	register int i,j,h;
	scanf("%d",&t);
	while(t--){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) g[i][j]=0;
		}flag=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				_s=getchar();
				while(_s!='a'&&_s!='b'&&_s!='*') _s=getchar();
				if(_s=='a') g[i][j]=1;
				if(_s=='b') g[i][j]=-1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) {
				if(i==j) continue;
				if(g[i][j]==g[j][i]){
				    flag=1;printf("YES\n");
			    	for(h=1;h<=m+1;h++)printf("%d ",(h&1)?i:j);
			    	break;
		    	}
			}   
			if(flag) break;
		}
		if(!flag){
			if(m&1) {
				printf("YES\n");
				for(i=1;i<=m+1;i++)printf("%d ",(i&1)?1:2);
			}
			else{
				for(i=1;i<=n;i++){
					now1=0;now2=0;
					for(j=1;j<=n;j++){
						if(i!=j){
							if(g[i][j]==1) now1=j;
							if(g[i][j]==-1) now2=j;
						}
					} 
					if(now1&&now2){
						flag=1;printf("YES\n");
						if(m%4==2){
							printf("%d ",now2);
							for(j=1;j<=m/2;j++)printf("%d %d ",i,(j&1)?now1:now2); 
						} 
						else{
							printf("%d ",i);
							for(j=1;j<=m/4;j++)printf("%d %d %d %d ",now1,i,now2,i);
						}
						break;
					}
				}
				if(!flag) printf("NO");
			}
		}
		printf("\n");
	}
}///////////