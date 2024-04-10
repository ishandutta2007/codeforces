#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,m,k,a[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;++i)scanf("%d",a+i);
		ll x=0,y=0;
		bool _x=0,_y=0;
		for(int i=1;i<=k;++i){
			int o=a[i]/n;
			if(o>1)x+=o;
			if(o>2)_x=1;
			o=a[i]/m;
			if(o>1)y+=o;
			if(o>2)_y=1;
		}
		bool ok=0;
		if(x>=1ll*m){
			if(m%2==0||_x)ok=1;
		}
		if(y>=1ll*n){
			if(n%2==0||_y)ok=1;
		}
		if(ok)printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}