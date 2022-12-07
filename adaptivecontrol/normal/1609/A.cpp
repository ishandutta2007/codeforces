#include<bits/stdc++.h>
using namespace std;
int T,n,a[16];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		long long cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
			while(a[i]%2==0)
				a[i]/=2,cnt++;
		}
		long long ans=0,pw=1;
		for(int i=0;i<n;i++)
			ans+=a[i];
		while(cnt--)
			pw=pw*2;
		long long qaq=0;
		for(int i=0;i<n;i++)
			qaq=max(qaq,1ll*a[i]);
		ans=ans-qaq+qaq*pw;
		cout<<ans<<endl;
	}
}