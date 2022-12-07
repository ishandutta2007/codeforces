#include<bits/stdc++.h>
using namespace std;
int T,n,l,r,c,ansl,ansr,anstot;
bool hasbig;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int L=1000000007,R=-1000000007;ansl=0;ansr=0;anstot=2000000007;hasbig=0;
		while(n--){
			scanf("%d%d%d",&l,&r,&c);
			if(l<L)ansl=c;
			if(r>R)ansr=c;
			if(l<L||r>R)hasbig=0,anstot=2000000007;
			L=min(l,L);R=max(r,R);
			if(L==l)ansl=min(ansl,c);
			if(R==r)ansr=min(ansr,c);
			if(L==l&&R==r)anstot=min(anstot,c),hasbig=1;
			printf("%d\n",min(ansl+ansr,anstot));
		}
	}
}