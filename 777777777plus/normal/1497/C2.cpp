#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,k;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=k-3;++i)cout<<1<<" ";
		n-=k-3;
		if(n&1){
			cout<<1<<" "<<n/2<<" "<<n/2<<endl;
		}
		else if(n%4==0){
			cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
		}
		else{
			cout<<n/2-1<<" "<<n/2-1<<" "<<2<<endl;
		}
	}
}