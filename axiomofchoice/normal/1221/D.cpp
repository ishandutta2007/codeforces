#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
ll dp[300010][3];
ll a[300010],b[300010];
int n,q;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>q;
	while(q--){
		cin>>n;
		repeat(i,0,n){
			cin>>a[i]>>b[i];
			repeat(j,0,3)
				dp[i][j]=b[i]*j;
		}
		repeat(i,1,n){
			repeat(k,0,3){
				ll t=1ll<<60;
				repeat(j,0,3)
				if(a[i-1]+j!=a[i]+k)
					t=min(t,dp[i-1][j]);
				dp[i][k]+=t;
			}
		}
		cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<endl;
	}
	return 0;
}