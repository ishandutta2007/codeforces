#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
int T;
ll sum[N],ans,now;
multiset<int> s[N];
il void gc(register char &c){c=getchar();while(c!='+'&&c!='-') c=getchar();}
int main(){
	scanf("%d",&T);it i,x;register char c;
	while(T--){
		gc(c),scanf("%d",&x),ans=now=0;
		for(i=0;(1<<i)<=x;++i);--i;
		if(c=='+') sum[i]+=x,s[i].insert(x);
		if(c=='-') sum[i]-=x,s[i].erase(s[i].find(x));
		for(i=0;i<30;++i) s[i].size()?ans+=(s[i].size()-((*s[i].begin())>(now<<1))),now+=sum[i]:0;
		printf("%lld\n",ans);
	}
	return 0;
}