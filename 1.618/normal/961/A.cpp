#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m,num[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a;
		scanf("%d",&a);
		num[a]++;
	}
	int mini = inf;
	for(int i=1;i<=n;i++) mini = min(mini,num[i]);
	printf("%d\n",mini);
	return 0;
}