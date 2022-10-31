#include<bits/stdc++.h>
#define N 10010
using namespace std;
int a[110][110];
int t[N],x[N],y[N],z[N];
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<q;i++){
		scanf("%d",&t[i]);
		if(t[i]==3) scanf("%d%d%d",&x[i],&y[i],&z[i]),--x[i],--y[i];
		else scanf("%d",&x[i]),x[i]--;
	}
	for(int i=q-1;i>=0;i--){
		if(t[i]==1){
			int tmp=a[x[i]][m-1];
			for(int j=m-1;j>0;j--){
				a[x[i]][j]=a[x[i]][j-1];
			}
			a[x[i]][0]=tmp;
		}
		else if(t[i]==2){
			int tmp=a[n-1][x[i]];
			for(int j=n-1;j>0;j--){
				a[j][x[i]]=a[j-1][x[i]];
			}
			a[0][x[i]]=tmp;
		}
		else{
			a[x[i]][y[i]]=z[i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d%c",a[i][j],j<m-1?' ':'\n');
		}
	}
	return 0;
}