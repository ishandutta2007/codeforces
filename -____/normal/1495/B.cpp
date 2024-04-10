#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111111;
int n,a[N],l[N],r[N];
int main(){
	int i,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=2;i<=n;i++)
		if(a[i-1]<a[i])
			l[i]=l[i-1]+1;
	for(i=n-1;i>=1;i--)
		if(a[i]>a[i+1])
			r[i]=r[i+1]+1;
	x=0;
	for(i=1;i<=n;i++)
		x=max(x,max(l[i],r[i]));
	if(x%2==1){
		cout<<0;
		return 0;
	}
	y=0;
	for(i=1;i<=n;i++)
		if(x==max(l[i],r[i]))
			y++;
	if(y>1){
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++)
		if(x==max(l[i],r[i]))
			y=i;
	z=l[y]+r[y]-x;
	if(x==z){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}