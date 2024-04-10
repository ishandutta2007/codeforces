#include<stdio.h>
int n,m,i,j,w[2001][3],v[2001],ct,a,b,c,t,tt,r[2001][3];
int min(int a,int b){if(a>b)return b;return a;}
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		w[a][0]=b,w[b][1]=a,w[a][2]=c;}
	for(i=1;i<=n;i++){
		if(w[i][1]==0&&w[i][0]!=0){
			v[i]=1;
			t=w[i][0];
			while(w[t][0]!=0){
				w[i][0]=w[t][0];
				w[i][2]=min(w[i][2],w[t][2]);
				tt=w[t][0];
				w[t][0]=w[t][1]=w[t][2]=0;
				t=tt;}}}
	for(i=1;i<=n;i++){
		if(w[i][0]!=0&&v[i]==1) r[ct][0]=i,r[ct][1]=w[i][0],r[ct++][2]=w[i][2];}
	printf("%d\n",ct);
	for(i=0;i<ct;i++) printf("%d %d %d\n",r[i][0],r[i][1],r[i][2]);
}