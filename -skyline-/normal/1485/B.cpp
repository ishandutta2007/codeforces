#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,a[100005],q,k;
ll s[100005];
int main(){
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=2;i<n;++i)s[i]=a[i+1]-a[i-1]-2+s[i-1];
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r)printf("%d\n",k-1);
		else printf("%I64d\n",s[r-1]-s[l]+k-a[r-1]+a[l+1]-3);
	}
    return 0;
}