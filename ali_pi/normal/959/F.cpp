#include<bits/stdc++.h>
using namespace std;
vector<int> base[100010];
int a[100010];
const long long MOD=1000000007;
long long qp(int x,int n){
	long long base=x,ans=1;
	for(int i=0;i<32;i++){
		if(1<<i&n)ans*=base,ans%=MOD;
		base*=base,base%=MOD;
	}
	return ans;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=0;j<base[i-1].size();j++)
			x=min(x,x^base[i-1][j]);
		for(int j=0;j<base[i-1].size();j++)
			base[i].push_back(min(base[i-1][j],x^base[i-1][j]));		
		if(x){
				base[i].push_back(x);
		}
	}
	int l,x;
	for(int i=1;i<=q;i++){
		cin>>l>>x;
		for(int j=0;j<base[l].size();j++)
			x=min(x,x^base[l][j]);
		if(x)cout<<0<<endl;
		else cout<<qp(2,l-base[l].size())<<endl;
	}
}