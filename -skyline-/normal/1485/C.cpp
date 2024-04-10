#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,x,y;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		ll ans=0;
		for(int k=1;k*k<=x;++k){
			int bl=k+1,br=min(x/k-1,y);
			if(bl<=br)ans+=br-bl+1;
		}
		printf("%I64d\n",ans);
	}
    return 0;
}