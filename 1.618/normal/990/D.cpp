#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
typedef long long ll;
int n,a,b;
int adj[maxn][maxn];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(2 <= n && n <= 3 && a == 1 && b == 1){
		puts("NO");
		return 0;
	}
	if(a >= 2 && b >= 2){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(a == 1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i != j) adj[i][j] = 1;
			}
		}
		for(int i=b;i<n;i++){
			adj[i][i+1] = adj[i+1][i] = 0;
		}
	}else{
		for(int i=a;i<n;i++){
			adj[i][i+1] = adj[i+1][i] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d",adj[i][j]);
			if(j == n) printf("\n");
		}
	}
	return 0;
}