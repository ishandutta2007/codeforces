#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+1000;
int n,ans=maxn,a,b[maxn],cnt=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]==1)
			cnt++;
	}
	if(cnt!=0){
		cout<<n-cnt;
		return 0;
	}
	for(int i=0;i<n;i++){
		a=b[i];
		for(int j=i+1;j<n;j++){
			a=__gcd(a,b[j]);
			if(a==1)
				ans=min(ans,j-i);		
		}
	}
	reverse(b,b+n);	
	for(int i=0;i<n;i++){
		a=b[i];
		for(int j=i+1;j<n;j++){
			a=__gcd(a,b[j]);
			if(a==1)
				ans=min(ans,j-i);		
		}
	}
	if(ans==maxn){
		cout<<-1;
		return 0;
	}
	cout<<ans+n-1;
	return 0;
}