#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;


int n,m;
int a[N],c[N];
ll cnt[N];

int qpow(int a,ll b){
	int r=1;
	while(b){
		if(b&1)r=r*a%m;
		b>>=1;
		a=a*a%m;
	}
	return r%m;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>m)return 0*puts("0");
	int ans=1;
	for(int i=1;i<=n;++i)
	for(int j=1;j<i;++j){
		(ans*=abs(a[i]-a[j])%m)%=m;
	}
	cout<<ans<<endl;
}