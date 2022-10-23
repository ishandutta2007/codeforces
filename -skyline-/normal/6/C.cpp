#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,a[100005],l,r,p,q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	l=0,r=n+1;
	while(r-l>1){
		if(p+a[l+1]<=q+a[r-1])++l,p+=a[l];
		else --r,q+=a[r];
	}
	printf("%d %d\n",l,n-l);
	return 0;
}