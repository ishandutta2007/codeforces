#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=110; typedef long long ll;
//#define int ll
int T,n;
char s[N][N];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,0,n)cin>>s[i];
		repeat(i,0,n)s[i][n]=s[n][i]='1';
		int f=true;
		repeat(i,0,n)
		repeat(j,0,n)
		if(s[i][j]=='1' && s[i+1][j]=='0' && s[i][j+1]=='0')
			f=false;
		cout<<(f?"YES":"NO")<<endl;
	}
	return 0;
}