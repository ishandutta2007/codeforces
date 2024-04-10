#include<bits/stdc++.h>
#define N 200100
using namespace std;
long long a[N];
int b[N];
int main(){
	int n;
	long long x=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++){
		a[i]=b[i]+x;
		x=max(x,a[i]);
	}
	for(int i=0;i<n;i++) printf("%lld ",a[i]);
	return 0;
}