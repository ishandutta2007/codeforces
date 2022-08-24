#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int v[100],n,m,w[21][21],ta,tb,c,D[30],s[30],mm;
struct A{
	char p[20];
	bool operator()(A r,A t){
		if(strcmp(r.p,t.p)<0)return 1;
		return 0;
	}
}q[20];
char a[20],b[20];
void DFS(int a){
	int i;
	if(a==n){
		if(c>mm){
			mm=c;
			for(i=0;i<n;i++) s[i]=v[i];}
		return;
	}
	for(i=0;i<n;i++) if(v[i]==1&&w[a][i]==1) break;
	if(i==n){
		c++;
		v[a]=1;
		DFS(a+1);
		v[a]=0;
		c--;}
	DFS(a+1);
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",q[i].p);}
	stable_sort(q,q+n,A());
	for(i=0;i<m;i++){
		scanf("%s",a);
		scanf("%s",b);
		for(j=0;j<n;j++){
			if(strcmp(a,q[j].p)==0)ta=j;
			if(strcmp(b,q[j].p)==0)tb=j;}
		w[ta][tb]=w[tb][ta]=1;
		for(j=0;j<19;j++)a[j]=0,b[j]=0;}
	DFS(0);
	printf("%d\n",mm);
	for(i=0;i<n;i++){
		if(s[i]==1)printf("%s\n",q[i].p);
	}
}