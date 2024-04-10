#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define N 300100
using namespace std;
int a[N];
int main(){
	int n,k;
	long long ans=0,ex=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ans+=a[i];
		if(a[i]&1){
			if(i&1) ex++;
			else ex--;
		}
	}
	printf("%lld\n",(ans-abs(ex))/2);
	return 0;
}