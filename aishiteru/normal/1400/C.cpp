#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll 
const int N=100005;
int T,n,o[N];
char s[N];
int main(){ 
	scanf("%d",&T);it i,x;
	while(T--){
		scanf("%s%d",s+1,&x),n=strlen(s+1);
		for(i=1;i<=n;++i) o[i]=1;
		for(i=1;i<=n;++i) if(s[i]=='0') i>=x?o[i-x]=0:0,i+x<=n?o[i+x]=0:0;
		for(i=1;i<=n;++i) if(s[i]=='1'&&(!((i>=x?o[i-x]:0)+(i+x<=n?o[i+x]:0)))) break;
		if(i<=n){puts("-1");continue;}
		for(i=1;i<=n;++i) printf("%d",o[i]);puts("");
	}
	return 0;
}