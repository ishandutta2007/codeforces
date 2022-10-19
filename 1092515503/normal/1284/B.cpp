#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1;
int n,mx[100100],mn[100100],t[1001000],s,T;
bool ok[100100];
void add(int x){
	while(x<=N)t[x]++,x+=x&-x;
}
int sum(int x){
	int sum=0;
	while(x)sum+=t[x],x-=x&-x;
	return sum;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%lld",&x),mn[i]=0x3f3f3f3f;
		while(x--){
			scanf("%lld",&y),y++;
			mx[i]=max(mx[i],y);
			if(mn[i]<y)ok[i]=true;
			else mn[i]=y;
		}
		if(!ok[i])add(mn[i]),T++;
	}
	s=n*n-T*T;
	for(int i=1;i<=n;i++){
		if(ok[i])continue;
		s+=sum(mx[i]-1);
	}
	printf("%lld\n",s);
	return 0;
}