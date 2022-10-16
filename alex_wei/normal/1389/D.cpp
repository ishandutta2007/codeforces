#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t,n,k,l,r,x,y;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>l>>r>>x>>y;
		ll c=max(r,y)-min(l,x);
		if(r<x||y<l){
			if(y<l)swap(l,x),swap(r,y);
			ll cost=0;
			for(int i=1;i<=n&&k;i++){
				cost+=x-r; int s=min(k,c);
				k-=s,cost+=s;
				if(k*2<=x-r+(k<=c?k:c+(k-c)*2)){
					cost+=k*2,k=0;
					break;
				}
			} if(k)cout<<cost+k*2<<endl;
			else cout<<cost<<endl;
		}
		else{
			ll s=min(r,y)-max(l,x);
			if(s*n>=k)cout<<0<<endl;
			else if(c*n>=k)cout<<k-s*n<<endl;
			else cout<<(k-c*n)*2+(c-s)*n<<endl;
		}
	}
	return 0;
}