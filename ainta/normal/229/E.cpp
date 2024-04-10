#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>V[1010];
int w[1010],O[1010],R[1010],S[1010];
double C[1010][1010],P[1010][1010],f;
int i,j,k,n,m,x,c,L,cnt;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d",&S[i]);
		for(j=0;j<S[i];j++){
			scanf("%d",&k);
			V[i].push_back(k);
			w[c++]=k;
		}
	}
	sort(w,w+c);
	L=w[c-n];
	C[0][0]=1;c=0;
	for(i=1;i<=1000;i++){
		C[i][0]=1;
		for(j=1;j<=1000;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];}
	for(i=1;i<=m;i++){
		for(j=0;j<V[i].size();j++){
			if(V[i][j]>L)cnt++,O[i]++;
			else if(V[i][j]==L) R[i]=1;
		}
		c+=R[i];
	}
	P[0][0]=1;
	for(i=1;i<=m;i++){
		if(!R[i]){
			for(j=0;j<=n-cnt;j++)P[i][j]=P[i-1][j]/C[S[i]][O[i]];
		}
		else{
			c--;
			for(j=0;j<n-cnt;j++){
				f=(double)(n-cnt-j)/(c+1);
				P[i][j]+=P[i-1][j]/C[S[i]][O[i]]*(1-f);
				P[i][j+1]+=P[i-1][j]/C[S[i]][O[i]+1]*f;
			}
			P[i][j]+=P[i-1][j]/C[S[i]][O[i]];
		}
	}
	printf("%.10lf\n",P[m][n-cnt]);
}