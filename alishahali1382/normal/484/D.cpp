#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const ll infll=1e18+100;
const int inf=1e9+100;
const int mod = 1000000007;
const int MAXN = 1000010;

ll m, n, q, tmp, k;
int A[MAXN];
int arr[MAXN];
bool b1[MAXN];
bool b2[MAXN];
ll dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>m;
	for (int i=1; i<=m; i++) cin>>arr[i];
	for (int i=1; i<=m; i++){
		if (i==1 || i==m || ((arr[i-1]<=arr[i] && arr[i]>=arr[i+1]) || (arr[i-1]>=arr[i] && arr[i]<=arr[i+1])) && !(arr[i]==arr[i-1] && arr[i]==arr[i+1])) b1[i]=true;
	}
	for (int i=2; i<m; i++) if (b1[i]){
		b2[i-1]=b2[i+1]=true;
	}
	for (int i=1; i<=m; i++){
		if (b1[i] || b2[i]) A[++n]=arr[i];
	}
	
	dp[2]=max(A[1], A[2])-min(A[1], A[2]);
	for (int i=3; i<=n; i++){
		dp[i]=dp[i-1];
		int mn=inf;
		int mx=-inf;
		for (int j=i; j>max(0, i-100); j--){
			mx=max(mx, A[j]);
			mn=min(mn, A[j]);
			dp[i]=max(dp[i], dp[j-1]+mx-mn);
		}
	}
	cout<<dp[n]<<endl;
	
	
	return 0;
}
/*
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