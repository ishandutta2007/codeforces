#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		ll g=0;
		bool flag=0;
		for(int i=1;i<=n;++i){
			if(g==0)g=i+1;
			else g=1ll*g*(i+1)/__gcd(g,(ll)i+1);
			if(g>2e9)g=2e9;
			if(a[i]%g==0)flag=1;
		}
		if(flag)puts("NO");
		else puts("YES");
	}
}