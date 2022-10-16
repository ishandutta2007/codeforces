#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,h,k,a,tmp,ans; 
int main(){
	cin>>n>>h>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(tmp+a<=h)tmp+=a;
		else{
			ll nd=tmp+a-h,t=(nd-1)/k+1;
			tmp=max(0ll,tmp-t*k);
			ans+=t; tmp+=a;
		}
	}
	cout<<ans+(tmp?(tmp-1)/k+1:0);
    return 0;
}