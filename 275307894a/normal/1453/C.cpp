#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[2039][2039],t,ans,maxn,minn,last,b[2039][2039];
char s;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				s=getchar();
				while(s<'0'||s>'9') s=getchar();
				a[i][j]=s-'0';
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) b[i][j]=a[j][i];
		}
		for(i=0;i<=9;i++){
			ans=0;last=0;
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++)if(!last&&a[j][k]==i) last=j;
				maxn=0;minn=1e9;
				for(k=1;k<=n;k++)if(a[j][k]==i){minn=k;break;}
				for(k=n;k;k--)if(a[j][k]==i){maxn=k;break;}
				if(!maxn) continue;
				ans=max(ans,max((maxn-minn)*(j-1),max((maxn-1)*(j-last),(n-minn)*(j-last)))); 
			}
			last=0;
			for(j=n;j;j--){
				for(k=1;k<=n;k++)if(!last&&a[j][k]==i) last=j;
				maxn=0;minn=1e9;
				for(k=1;k<=n;k++)if(a[j][k]==i){minn=k;break;}
				for(k=n;k;k--)if(a[j][k]==i){maxn=k;break;}
				if(!maxn) continue;
				ans=max(ans,max((maxn-minn)*(n-j),max((maxn-1)*(last-j),(n-minn)*(last-j)))); 
			}
			last=0;
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++)if(!last&&b[j][k]==i) last=j;
				maxn=0;minn=1e9;
				for(k=1;k<=n;k++)if(b[j][k]==i){minn=k;break;}
				for(k=n;k;k--)if(b[j][k]==i){maxn=k;break;}
				if(!maxn) continue;
				ans=max(ans,max((maxn-minn)*(j-1),max((maxn-1)*(j-last),(n-minn)*(j-last)))); 
			}
			last=0;
			for(j=n;j;j--){
				for(k=1;k<=n;k++)if(!last&&b[j][k]==i) last=j;
				maxn=0;minn=1e9;
				for(k=1;k<=n;k++)if(b[j][k]==i){minn=k;break;}
				for(k=n;k;k--)if(b[j][k]==i){maxn=k;break;}
				if(!maxn) continue;
				ans=max(ans,max((maxn-minn)*(n-j),max((maxn-1)*(last-j),(n-minn)*(last-j)))); 
			}
			printf("%d ",ans);
		}
		printf("\n");
	}
}