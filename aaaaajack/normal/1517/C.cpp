#include<bits/stdc++.h>
using namespace std;
int a[510][510];
int b[510],c[510];
bool cmp(int i,int j){
	return b[i]<b[j];
}
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		b[x]=i;
		c[i]=n-i;
	}
	for(int i=0;i<n;i++){
		sort(c,c+i+1,cmp);
		for(int j=0;j<=i;j++){
			a[n-i+j][j]=c[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}