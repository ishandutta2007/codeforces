#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,m,l,r,s,i;
	long long c,num,sum;
	for(cin>>T;T--;cout<<l<<'\n'){
		cin>>n>>m,l=0,r=n;
		while(l<=r){
			s=l+r>>1;
			for(i=num=sum=0,c=1;i<=s;++i,c=c*(s-i+1)/i)if(num+=c,sum+=c*i,num>=n){
				if(sum-(num-n)*i<=s*1ll*m)r=s-1;else l=s+1;
				goto gg;
			}
			l=s+1;
			gg:;
		}
	}
	return 0;
}