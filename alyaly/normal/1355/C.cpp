#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int a,b,c,d,ans,n,aans;
signed main(){
//	srand(time(0));
	cin>>a>>b>>c>>d;
	for(int x=a;x<=b;x++){
//		for(int z=c;z<=d;z++){
//			if(c>=z-x+1) aans+=min(c,z)-max(b,z-x+1)+1;
//		}
		n=min(d,c+x-1)-max(c,b+x)+1;
		int sz=max(c,b+x);
		if(b+x-1>=c) ans+=(min(b+x,d+1)-c)*(c-b+1);
		if(n>0) ans+=n*(c-sz+x)-n*(n-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
/*

*/