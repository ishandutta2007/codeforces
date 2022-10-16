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
 
int t;
void solve(){
	int n;
	cin>>n;
	if(n==1)puts("-1");
	else{
		for(int i=1;i<n;i++)cout<<'5';
		cout<<4<<endl;
	}
}
int main(){
	cin>>t;
	while(t--)solve();
	return 0;
}