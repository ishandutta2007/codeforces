#include<bits/stdc++.h>
#define ll long long
#define P 250
#define Q 300
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
void Min(int &a,int b){a = min(a,b);}
string s;
int dp[105][P*2+15][Q*2+15],n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>s; s = "0000"+s; n = s.length();
 	memset(dp,0x3f,sizeof dp);
 	dp[0][P][Q] = 0;
 	rep(i,0,n-1){
 		rep(j,-P,P){
 			rep(k,-Q,Q){
 				rep(h,-6,6){
 					int kk = k+h,
 					jj = j*10+s[i]-'0'-kk;
 					if(abs(jj)>P || abs(kk)>Q) continue;
 					Min(dp[i+1][jj+P][kk+Q],dp[i][j+P][k+Q]+abs(h)*(n-i));
 				}
 			}
 		}
 	}
 	int ans = inf;
 	rep(k,-Q,Q) Min(ans,dp[n][P][k+Q]);
 	cout << ans;
	return 0;
}