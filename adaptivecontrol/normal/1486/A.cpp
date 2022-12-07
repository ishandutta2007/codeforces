#include<bits/stdc++.h>
using namespace std;
int T,n,h[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		long long sum=0;
		bool ok=1;
		for(int i=0;i<n;i++){
			cin>>h[i];
			sum+=h[i];
			if(sum<(i+1)*i/2)
				ok=0;
		}
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}