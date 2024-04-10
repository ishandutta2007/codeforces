#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[139],l,r,mid;
inline int check(int x){
	printf("> %d\n",x);cout<<endl;
	scanf("%d",&x);
	return x;
}
int main(){
	register int i;
	srand((unsigned int) time(0));
	scanf("%d",&n);
	l=-1;r=1e9;
	while(l+1<r){
		mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(i=1;i<=30;i++){
		x=(rand()*rand())%n+1;
		printf("? %d\n",x);cout<<endl;
		scanf("%d",&a[i]);
	}
	sort(a+1,a+31);x=a[2]-a[1];
	for(i=3;i<=30;i++)x=__gcd(x,a[i]-a[i-1]);
	printf("! %d %d\n",r-x*(n-1),x); 
}