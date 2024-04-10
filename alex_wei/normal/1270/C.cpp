#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100005],sum,xo;
int main(){
	cin>>t;
	while(t--){
		cin>>n; sum=xo=0;
		for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i],xo^=a[i];
		printf("2\n%lld %lld\n",xo,sum+xo);
	}
    return 0;
}