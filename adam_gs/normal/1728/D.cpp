#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e3+7;
int dp[LIM][LIM];
void solve() {
string s;
cin >> s;
int n=s.size();
rep(i, n) rep(j, n) dp[i][j]=0;
rep(i, n-1) if(s[i]!=s[i+1]) dp[i][i+1]=1;
for(int d=4; d<=n; d+=2) rep(i, n-d+1) {
int j=i+d-1;
dp[i][j]=-1;
if(dp[i+1][j-1]!=-1 && dp[i+2][j]!=-1) {
int p=1;
if(dp[i+2][j]==0) {
if(s[i]>s[i+1]) p=min(p, -1);
else if(s[i]==s[i+1]) p=min(p, 0);
}
if(dp[i+1][j-1]==0) {
if(s[i]>s[j]) p=min(p, -1);
else if(s[i]==s[j]) p=min(p, 0);
}
dp[i][j]=max(dp[i][j], p);
}
if(dp[i+1][j-1]!=-1 && dp[i][j-2]!=-1) {
int p=1;
if(dp[i][j-2]==0) {
if(s[j]>s[j-1]) p=min(p, -1);
else if(s[j]==s[j-1]) p=min(p, 0);
}
if(dp[i+1][j-1]==0) {
if(s[i]<s[j]) p=min(p, -1);
else if(s[i]==s[j]) p=min(p, 0);
}
dp[i][j]=max(dp[i][j], p);
}
}
if(dp[0][n-1]==0) cout << "Draw\n";
else if(dp[0][n-1]==1) cout << "Alice\n";
else cout << "Bob\n";
}
int main() {
ios_base::sync_with_stdio(0); cin.tie(0);
int _=1;
cin >> _;
while(_--) solve();
}