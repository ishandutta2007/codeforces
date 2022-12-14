#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf; const lf err=1e-7;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
#define orz(x) {cout<<#x": "<<x<<endl;}
const int N=100010;
const int inf=1e9;
const int mod=1e9+7;
//#define int ll
int n,f[3],a[N],ans=0;
int dp[110][110][2];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f[0]=n/2;
	f[1]=(n+1)/2;
	repeat(i,1,n+1){
		cin>>a[i];
		if(a[i]==0)a[i]=-1;
		else a[i]%=2,f[a[i]]--;
	}
	repeat(i,0,n+1)
	repeat(j,0,f[1]+1)
	repeat(k,0,2){
		dp[i][j][k]=inf;
		if(i==0 && j==0){
			dp[i][j][k]=0;
		}
		if(i==0)continue;
		if(a[i]!=-1){
			if(a[i]==k)
				dp[i][j][k]=
				min(dp[i-1][j][k],dp[i-1][j][k^1]+1);
			else
				dp[i][j][k]=inf;
		}
		else{
			if(j-k>=0)
				dp[i][j][k]=
				min(dp[i-1][j-k][k],dp[i-1][j-k][k^1]+1);
			else dp[i][j][k]=inf;
		}
	}
	cout<<min(dp[n][f[1]][0],dp[n][f[1]][1])<<endl;
	return 0;
}