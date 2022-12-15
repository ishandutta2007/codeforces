#include <bits/stdc++.h>
using namespace std;

int n,a[100000],mx[100000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	for(int i=n-2;i>=0;i--)
		mx[i] = max(mx[i+1],a[i+1]);

	for(int i=0;i<n;i++) 
		printf("%d ",max(mx[i]+1-a[i],0));

	return 0;
}