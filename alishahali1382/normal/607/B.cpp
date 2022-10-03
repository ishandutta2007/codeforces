#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 510;

int n, m, k, ans, x, q;
int A[MAXN];
int dp[MAXN][MAXN];
int f(int l, int r){
	if (l>r || r>n || l<1) return 0;
	if (dp[l][r]!=-1) return dp[l][r];
	if (l==r) return dp[l][r]=1;
	if (l+1==r){
		if (A[l]==A[l+1]) return dp[l][r]=1;
		return dp[l][r]=2; 
	}
	//if (l==1 && r==3) cerr<<dp[l][r]<<endl;
	dp[l][r]=f(l+1, r)+1;
	//if (l==1 && r==3) cerr<<dp[l][r]<<endl;
	if (A[l]==A[r]) dp[l][r]=min(dp[l][r], f(l+1, r-1));
	//if (l==1 && r==3) cerr<<dp[l][r]<<endl;
	for (int i=l+1; i<r; i++){
		if (A[l]==A[i]) dp[l][r]=min(dp[l][r], f(l, i) + f(i+1, r));
	}
	return dp[l][r];
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(dp, -1, sizeof(dp));
	cout<<f(1, n)<<endl;
	/*
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cerr<<f(i, j)<<' ';cerr<<endl;
	}
	*/
	return 0;
}
/*
                                                                                                            __                    .----.                    
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.     
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )    
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /     
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /      
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /       
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /        
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '         
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-') 
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''  
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'      
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'         
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'            
 */