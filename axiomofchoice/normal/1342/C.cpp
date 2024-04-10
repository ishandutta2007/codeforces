#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll;
#define int ll
int T;
int s[N];
int a,b,q;
int work(int x){
	return x/(a*b)*s[a*b]+s[x%(a*b)];
}
signed main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>q;
		repeat(i,1,a*b+1)
			s[i]=s[i-1]+(i%a%b!=i%b%a);
		while(q--){
			int x,y; cin>>x>>y;
			cout<<work(y)-work(x-1)<<' ';
		}
		cout<<endl;
	}
	return 0;
}