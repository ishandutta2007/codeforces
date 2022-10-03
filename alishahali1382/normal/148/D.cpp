#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1010;

int w, b, s, tmp;
ld dp[MAXN][MAXN][2];  //  dp[i][j][x]:  x=0 ==> princess 

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>w>>b;
	for (int i=0; i<MAXN; i++){
		dp[i][0][0]=1;
		dp[i][0][1]=0;
		dp[0][i][0]=0;
		dp[0][i][1]=0;
	}
	for (int i=1; i<=w; i++){
		for (int j=1; j<=b; j++){
			ld tmp=i+j;
			dp[i][j][0] = dp[i][j-1][1]*j/tmp + i/tmp;
			dp[i][j][1] = (j/tmp)*(dp[i][j-2][0] * (j-1)/(tmp-1) + dp[i-1][j-1][0] * i/(tmp-1));
			//dp[i][j][1] = 1-dp[i][j][1];
		}
	}
	cout<<setprecision(9)<<fixed<<dp[w][b][0]<<endl;
		
	return 0;
}