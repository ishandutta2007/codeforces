#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,c[N],s[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c[i]>>s[i];
		c[i]=min(c[i],s[i]);
		ll w1=s[i]/c[i];
		ll w2=(s[i]+c[i]-1)/c[i];
		ll cnt=s[i]%c[i];
		cout<<w2*w2*cnt+w1*w1*(c[i]-cnt)<<endl;
	}
	
}