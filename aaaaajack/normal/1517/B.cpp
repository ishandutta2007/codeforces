#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int a[110][110],b[110][110]={},cur[110]={};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
			sort(a[i],a[i]+m);
		}
		for(int j=0;j<m;j++){
			int mx=-1;
			for(int i=0;i<n;i++){
				if(mx<0 || a[i][cur[i]]<a[mx][cur[mx]]) mx=i;
			}
			b[mx][j]=a[mx][cur[mx]++];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!b[i][j]){
					b[i][j]=a[i][cur[i]++];
				}
				printf("%d ",b[i][j]);
			}
			puts("");
		}
	}
	return 0;
}