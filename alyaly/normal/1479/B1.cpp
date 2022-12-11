#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int T,n,a[N+1],ans,np,nq;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=np&&a[i]!=nq){
			if(i==n||a[i+1]==np)ans++,np=a[i];
			else ans++,nq=a[i];
		}else if(a[i]!=np)ans++,np=a[i];
		else if(a[i]!=nq)ans++,nq=a[i];
		else np=a[i];
	}
	cout<<ans<<endl;
	return 0;
}