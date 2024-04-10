#include<bits/stdc++.h>
#define I inline
#define RI register int
#define rep(i,a,b) for(RI i=(a);i<=(b);++i)
#define dow(i,a,b) for(RI i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,n,k,h[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		RI mx,mi;bool flag=1;
		scanf("%d",&h[1]);mx=mi=h[1];
		rep(i,2,n){	
			scanf("%d",&h[i]);
			if(h[i]<=mx+k-1)
				mx=min(mx+k-1,h[i]+k-1),mi=max(h[i],mi-k+1);
			else flag=0;
			if(mi>mx) flag=0;
		}
		puts(flag&&mi==h[n]?"YES":"NO");
	}
	return 0;
}