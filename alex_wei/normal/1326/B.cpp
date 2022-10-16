#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define pii pair <int,int>
#define all(v) v.begin(),v.end()
#define sor(v) sort(all(v))
#define rev(v) reverse(all(v))
#define mem(v,x) memset(v,x,sizeof(v))
 
ll n,b[200005],v;
 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		cout<<v+b[i]<<" ";
		v=max(v,v+b[i]);
	}
	return 0;
}