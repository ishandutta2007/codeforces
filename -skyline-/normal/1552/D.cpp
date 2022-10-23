#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,a[12],p[1105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",a+i),a[i]=abs(a[i]);
		for(int _=0;_<(1<<n);++_){
			p[_]=0;
			for(int i=0;i<n;++i)if(_&(1<<i))p[_]+=a[i];
		}
		sort(p,p+(1<<n));
		bool ok=0;
		for(int i=1;i<(1<<n);++i)if(p[i]==p[i-1])ok=1;
		if(ok)puts("YES");
		else puts("NO");
	}
			
    return 0;
}