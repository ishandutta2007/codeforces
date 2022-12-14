#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
for(int i=(a),i##end=(b);i<i##end;i++)
ll a[200010];
ll n;
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>n;
	repeat(i,0,n)
		cin>>a[i];
	
	ll maxnow=0,maxs=0;
	repeat(i,0,61){
		ll s=1ll<<i,now=0;
		repeat(j,0,n){
			if(a[j]%s==0 && a[j]%(2*s)!=0){
				now++;
			}
			if(now>maxnow){
				maxnow=now;
				maxs=s;
			}
		}
	}
	cout<<n-maxnow<<endl;
	ll s=maxs;
	repeat(j,0,n){
		if(a[j]%s==0 && a[j]%(2*s)!=0);
		else cout<<a[j]<<' ';
	}
	cout<<endl;
	return 0;
}