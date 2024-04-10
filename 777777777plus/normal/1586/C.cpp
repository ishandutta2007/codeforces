#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n,m,Q,c[N];
string s[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i+1<=n;++i)
	for(int j=0;j+1<m;++j)
	if(s[i+1][j]=='X'&&s[i][j+1]=='X'){
		c[j+1]=1;
	}
	cin>>Q;
	for(int i=1;i<=m;++i)c[i]+=c[i-1];
	for(int i=1,l,r;i<=Q;++i){
	    cin>>l>>r;
		if(c[r-1]==c[l-1]){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}