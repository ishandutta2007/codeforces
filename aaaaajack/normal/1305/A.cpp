#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	int a[1010],b[1010];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');
		for(int i=0;i<n;i++) printf("%d%c",b[i],i==n-1?'\n':' ');
	}
	return 0;
}