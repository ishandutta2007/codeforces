#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
int main(){
	//ios_base::sync_with_stdio(false);
	int a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	int x=a1*(k1-1)+a2*(k2-1);
	int ans=max(0,n-x);
	cout<<ans<<' ';
	
	if(k1>k2)swap(k1,k2),swap(a1,a2);
	if(n<=k1*a1)
		ans=n/k1;
	else{
		n-=k1*a1;
		ans=a1+n/k2;
	}
	cout<<ans<<endl;
	return 0;
}