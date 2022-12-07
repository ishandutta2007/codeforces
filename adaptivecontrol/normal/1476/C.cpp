#include<bits/stdc++.h>
using namespace std;
int T,n,c[100003],a[100003],b[100003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>c[i];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];a[n]=0;b[n]=0;
		long long ans=0,nw=fabs(a[1]-b[1]);
		for(int i=1;i<n;i++){
			nw=nw+c[i]+1-fabs(a[i+1]-b[i+1]);
//			cout<<nw<<' ';
			ans=max(ans,nw+int(fabs(a[i+1]-b[i+1])));
			nw=max(nw,1ll*int(fabs(a[i+1]-b[i+1])));
			if(a[i+1]==b[i+1])nw=0;
		}//ans=max(ans,nw+c[n-1]-1);
		cout<<ans<<endl;
	}
}