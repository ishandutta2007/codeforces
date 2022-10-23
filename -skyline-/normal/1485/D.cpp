#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,a[505][505];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int x;
			scanf("%d",&x);
			if((i+j)&1)a[i][j]=720720;
			else a[i][j]=720720-x*x*x*x;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j)printf("%d ",a[i][j]);
		printf("%d\n",a[i][m]);
	}
    return 0;
}