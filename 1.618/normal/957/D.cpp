#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;
typedef long long ll;
int n,k[maxn],a[maxn];
ll sumk,suma;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		sumk += (ll)k[i];
	}
	a[1] = 1;
	for(int i=2;i<=n;i++){
		a[i] = max(a[i-1],k[i]+1);
	}
	for(int i=n-1;i>=1;i--){
		a[i] = max(a[i],a[i+1] - 1);
	}
	for(int i=1;i<=n;i++) suma += (ll)a[i];
	printf("%I64d\n",suma - sumk - (ll)n);
	return 0;
}