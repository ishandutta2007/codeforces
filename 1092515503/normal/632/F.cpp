#include<bits/stdc++.h>
using namespace std;
int n;
int a[6250000],ord[6250000];
bitset<2500>N[2500],M[2500];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i*n+j]),ord[i*n+j]=i*n+j;
	sort(ord,ord+n*n,[](int u,int v){return a[u]>a[v];});
	for(int i=0;i<n;i++)if(a[i*n+i]){puts("NOT MAGIC");return 0;}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(a[i*n+j]!=a[j*n+i]){puts("NOT MAGIC");return 0;}
	for(int i=0,j=0;i<n*n;i=j){
		while(j<n*n&&a[ord[j]]==a[ord[i]])N[ord[j]/n][ord[j]%n]=1,M[ord[j]%n][ord[j]/n]=1,j++;
		for(int k=i;k<j;k++)if((N[ord[k]/n]|M[ord[k]%n]).count()!=n){puts("NOT MAGIC");return 0;}
	}
	puts("MAGIC");
	return 0;
}