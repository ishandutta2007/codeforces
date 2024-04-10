#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
typedef long long LL;
int n,a[N],c[N];
int main(){
	int i;
	LL s;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",a+i,c+i),s+=c[i],c[i]+=a[i];
	sort(a+1,a+n+1);
	sort(c+1,c+n+1);
	for(i=1;i<n;i++)
		if(c[i]<a[i+1])
			s+=a[i+1]-c[i];
	cout<<s;
	return 0;
}