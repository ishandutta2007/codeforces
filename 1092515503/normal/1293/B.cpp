#include<bits/stdc++.h>
using namespace std;
int n;
double f[100100];
int main(){
	scanf("%d",&n);
	for(int i=n-1;i>=0;i--)f[i]=f[i+1]+1.0/(i+1);
	printf("%lf\n",f[0]);
	return 0;
}