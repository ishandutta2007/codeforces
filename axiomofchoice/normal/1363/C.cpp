#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int T,n,x;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		int deg=0;
		repeat(i,0,n-1){
			int u,v; cin>>u>>v;
			if(u==x || v==x)deg++;
		}
		if(deg<=1 || n%2==0)cout<<"Ayush"<<endl;
		else cout<<"Ashish"<<endl;
	}
	return 0;
}