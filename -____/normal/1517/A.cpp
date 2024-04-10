#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int T,x;
	LL n;
	cin>>T;
	while(T--){
		cin>>n;
		if(n%2050){
			cout<<-1<<endl;
			continue;
		}
		n/=2050;
		x=0;
		while(n){
			x+=n%10;
			n/=10;
		}
		cout<<x<<endl;
	}
	return 0;
}