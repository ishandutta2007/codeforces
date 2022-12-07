#include<bits/stdc++.h>
using namespace std;
long long T,n,A,B,a[100003],b[100003];
int main(){
	cin>>T;
	while(T--){
		cin>>A>>B>>n;
		for(int i=0;i<n;i++)
			scanf("%lld",a+i);
		for(int i=0;i<n;i++)
			scanf("%lld",b+i);
		int maxn=0;
		for(int i=0;i<n;i++){
			B-=((b[i]-1)/A+1)*a[i];
			maxn=max(maxn*1ll,a[i]);
		}
		if(B+maxn>=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}