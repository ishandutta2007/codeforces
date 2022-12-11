#include<bits/stdc++.h>
#include<vector>
using namespace std;
int T,n,p,q,lp,lq;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		lp=lq=0;
		bool ffl=0;
		for(int i=1;i<=n;i++){
			cin>>p>>q;
			if(q-lq>p-lp||p<lp||q<lq){
				ffl=1;
			}
			lp=p;
			lq=q;
		}
		if(!ffl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
10 13
RLLRLRRLRL
*/