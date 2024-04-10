#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n,k;
void solve(){
	cin>>n>>k,k--;
	if(n<62&&k>>n-1)return puts("-1"),void();
	for(int i=1,p=1;i<=n;i=p+1,p=i){
		while(p<n&&n-p<=62&&(k>>n-p-1)&1)p++;
		for(int j=p;j>=i;j--)cout<<j<<" ";
	} cout<<endl;
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}