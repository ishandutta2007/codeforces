#include<bits/stdc++.h>
using namespace std;
int T,n,k;
long long p[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		long long ans=0;
		for(int i=0;i<n;i++)
			cin>>p[i];
		for(int i=1;i<n;i++)
			p[i]+=p[i-1];
		for(int i=1;i<n;i++){
			if(p[i]*100<=p[i-1]*(100+k))
				continue;
			else
				ans=max(ans,(p[i]*100-p[i-1]*(100+k)+k-1)/k);
//			p[i]*1==p[i-1]*(1+k)
		}
		cout<<ans<<endl;
	}
}