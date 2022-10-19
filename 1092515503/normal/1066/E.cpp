#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
char a[200011],b[200011];
int A,B,t[200011],ans,pov[200011];
int lowbit(int x){
	return x&-x;
}
void add(int x){
	while(x<=max(A,B))t[x]++,t[x]%=MOD,x+=lowbit(x);
}
int sum(int x){
	int s=0;
	while(x)s+=t[x],x-=lowbit(x),s%=MOD;
	return s;
}
signed main(){
	scanf("%lld%lld%s%s",&A,&B,a+1,b+1),pov[0]=1;
	for(int i=1;i<=A;i++)pov[i]=(pov[i-1]<<1)%MOD;
	for(int i=1;i<=B;i++)if(b[i]=='1')add(i);
	for(int i=1;i<=A;i++)if(a[i]=='1'&&B-A+i>=0)ans+=sum(B-A+i)*pov[A-i]%MOD,ans%=MOD;
	printf("%lld\n",ans);
	return 0;
}