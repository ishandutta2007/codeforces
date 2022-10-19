#include<bits/stdc++.h>
//#define only_one_test
using namespace std;
int a[1000005],b[1000005],c[1000005];
int main(){
	int T=1;
#ifndef only_one_test
	cin>>T;
#endif
	while(T--){
		int l,r,ans=0;
		cin>>l>>r;
		for(int i=0;i<=25;++i){long long a1=(r>>(i+1))<<i;
		long long a2=max(0ll,(r&((1ll<<(i+1))-1))-(1ll<<i)+1);
		long long a3=((l-1)>>(i+1))<<i;
		long long a4=max(0ll,((l-1)&((1ll<<(i+1))-1))-(1ll<<i)+1);
		ans=max(0ll+ans,a1+a2-a3-a4);
		}
		cout<<r-l+1-ans<<endl;
	}
	return 0;
}