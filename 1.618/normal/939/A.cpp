#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int n,f[5005];
bool vis[5005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=n;i++){
		if(f[f[f[i]]] == i){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}