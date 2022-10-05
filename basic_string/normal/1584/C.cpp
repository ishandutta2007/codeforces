#include<bits/stdc++.h>
using namespace std;
map<int,int>ma,mb;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;ma=mb={};
		for(i=1;i<=n;++i)cin>>j,++ma[j];
		for(i=1;i<=n;++i)cin>>j,++mb[j];
		for(i=109;i>-109;--i){
			if(mb[i]){
				if(ma[i])mb[i]-=ma[i],ma[i]=0;
				if(mb[i]<0)goto gg;
				if(mb[i]){
					if(ma[i-1]>=mb[i])ma[i-1]-=mb[i],mb[i]=0;
					else goto gg;
				}
			}
		}
		cout<<"YES\n";goto g2;
		gg:;
		cout<<"NO\n";g2:;
	}
	return 0;
}