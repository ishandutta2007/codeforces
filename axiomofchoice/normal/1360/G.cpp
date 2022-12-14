#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=110; typedef long long ll;
//#define int ll
int T,n,m,a,b;
string ans[N];
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>a>>b;
		if(n*a!=m*b){cout<<"NO"<<endl; continue;}
		cout<<"YES"<<endl;
		int x=0;
		repeat(i,0,n){
			ans[i].assign(m,'0');
			repeat(j,0,a){
				ans[i][(x++)%m]='1';
			}
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}