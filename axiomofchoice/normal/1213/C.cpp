#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n,m,m2,ans,s,a[20];
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		m2=m%10;
		
		s=ans=0;
		for(int i=0;i<10;i++){
			a[i]=(m2*i)%10;
			s+=a[i];
		}
		ans+=s*(n/(m*10));
		n%=m*10;
		n/=m;
		for(int i=1;i<=n;i++)
			ans+=a[i];
		cout<<ans<<endl;;
	}
	return 0;
}