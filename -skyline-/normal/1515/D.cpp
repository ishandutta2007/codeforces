#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,l,r,cl[200005],cr[200005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&l,&r);
		for(int i=1;i<=n;++i)cl[i]=cr[i]=0;
		for(int i=1;i<=l;++i){
			int x;
			scanf("%d",&x);
			++cl[x];
		}
		for(int i=1;i<=r;++i){
			int x;
			scanf("%d",&x);
			++cr[x];
		}
		int L=0,R=0,L1=0,R1=0;
		for(int i=1;i<=n;++i){
			if(cl[i]>cr[i])L+=cl[i]-cr[i],L1+=(cl[i]-cr[i])/2;
			else R+=cr[i]-cl[i],R1+=(cr[i]-cl[i])/2;
		}
		if(L>R)printf("%d\n",(L+R)/2+max(0,L-R-L1*2)/2);
		else printf("%d\n",(L+R)/2+max(0,R-L-R1*2)/2);
	}
    return 0;
}