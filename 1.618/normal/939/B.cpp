#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
const ll inf = 1000000000000000000ll;
ll n,k,a[100005];
ll minrem = inf,minind,minnum;
int main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%I64d",&a[i]);
		if(n % a[i] < minrem){
			minrem = n % a[i];
			minind = i;
			minnum = n / a[i];
		}
	}
	printf("%I64d %I64d\n",minind,minnum);
	return 0;
}