#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<memory.h>
#include<assert.h>
#include<numeric>
#include<limits.h>
#define ll    long long
using namespace std;
ll f[1000005]={1},a[1005],n,ans=1;
ll fpower(ll x){
	ll res=1,k=1000000005;
	while(k){
		if(k&1)res=(res*x)%1000000007;
		k>>=1;
		x=(x*x)%1000000007;
	}
	return res;
}
ll ope(ll x,ll y){
	return (f[x]*fpower((f[y]*f[x-y])%1000000007)%1000000007)%1000000007;
}
int main(){
	for(int i=1;i<=1000003;i++)f[i]=(f[i-1]*i)%1000000007;
	scanf("%I64d",&n);
	ll s=0;
	for(int i=1;i<=n;i++){
		scanf("%I64d",a+i);
		s+=a[i];
	}
	for(int i=n;i;i--)ans=(ans*ope(s-1,a[i]-1))%1000000007,s-=a[i];
	printf("%I64d\n",ans);
	return 0;
}