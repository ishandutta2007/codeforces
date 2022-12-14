#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int T,n,m,a,b;
string s;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>a>>b; b=min(b,2*a);
		int ans=0;
		repeat(i,0,n){
			cin>>s;
			repeat(j,0,m)
			if(s[j]=='.'){
				if(j!=m-1 && s[j+1]=='.'){
					s[j+1]='*';
					ans+=b;
				}
				else ans+=a;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}