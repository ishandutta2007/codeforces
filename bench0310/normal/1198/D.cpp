#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

const int N=50;
int n;
string s[N];
int dp[N][N][N][N];

int solve(int ar,int ac,int br,int bc)
{
    if(ar>br||ac>bc) return 0;
    if(dp[ar][ac][br][bc]!=-1) return dp[ar][ac][br][bc];
    int cnt=0;
    for(int o=ar;o<=br;o++) for(int i=ac;i<=bc;i++) cnt+=(s[o][i]=='#');
    if(cnt==0) return dp[ar][ac][br][bc]=0;
    dp[ar][ac][br][bc]=max(br-ar+1,bc-ac+1);
    for(int o=ar;o<=br;o++) dp[ar][ac][br][bc]=min(dp[ar][ac][br][bc],solve(ar,ac,o,bc)+solve(o+1,ac,br,bc));
    for(int i=ac;i<=bc;i++) dp[ar][ac][br][bc]=min(dp[ar][ac][br][bc],solve(ar,ac,br,i)+solve(ar,i+1,br,bc));
    return dp[ar][ac][br][bc];
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> s[i];
	for(int a=0;a<N;a++) for(int b=0;b<N;b++) for(int c=0;c<N;c++) for(int d=0;d<N;d++) dp[a][b][c][d]=-1;
	cout << solve(0,0,n-1,n-1) << endl;
	return 0;
}