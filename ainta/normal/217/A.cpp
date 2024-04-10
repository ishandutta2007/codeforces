#include<stdio.h>
int n,w[101][101],C,p[101][2];
bool v[101];
void DFS(int a){
	int i;
	for(i=1;i<=n;i++){
		if(!v[i]&&w[a][i]==1){
			v[i]=true;
			DFS(i);
		}
	}
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",&p[i][0],&p[i][1]);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(p[i][0]==p[j][0]||p[i][1]==p[j][1])w[i][j]=w[j][i]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			DFS(i);
			C++;
		}
	}
	printf("%d\n",C-1);
}