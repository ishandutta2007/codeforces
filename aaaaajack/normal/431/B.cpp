#include<cstdio>
using namespace std;
int main(){
	int g[10][10],i,j,k,l,m,ans=0,temp;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&g[i][j]);
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(j==i) continue;
			for(k=0;k<5;k++){
				if(k==j||k==i) continue;
				for(l=0;l<5;l++){
					if(l==i||l==j||l==k) continue;
					for(m=0;m<5;m++){
						if(m==i||m==j||m==l||m==k) continue;
						temp=g[i][j]+g[j][i]+g[j][k]+g[k][j]+2*(g[k][l]+g[l][k]+g[l][m]+g[m][l]);
						if(temp>ans) ans=temp;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}