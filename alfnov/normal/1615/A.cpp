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
		int n,x,y,z;
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%n==0)cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}