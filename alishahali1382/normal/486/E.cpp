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
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 100010;

int n, k, b, x, y, ans;
int A[MAXN];
int dp1[MAXN];
int dp2[MAXN];
int mn[MAXN];
int out[MAXN];
int cnt[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(mn+1, 63, sizeof(mn));
	for (int i=1; i<=n; i++){
		int x=lower_bound(mn, mn+MAXN, A[i])-mn;
		dp1[i]=x;
		ans=max(ans, x);
		mn[x]=min(mn[x], A[i]);
	}
	for (int i=1; i<=n; i++) A[i]=-A[i];
	reverse(A+1, A+n+1);
	memset(mn+1, 63, sizeof(mn));
	for (int i=1; i<=n; i++){
		int x=lower_bound(mn, mn+MAXN, A[i])-mn;
		dp2[n-i+1]=x+1;
		ans=max(ans, x);
		mn[x]=min(mn[x], A[i]);
	}
	//for (int i=1; i<=n; i++) cerr<<dp1[i]<<' ';cerr<<endl;
	//for (int i=1; i<=n; i++) cerr<<dp2[i]<<' ';cerr<<endl;
	//cerr<<ans<<endl;
	for (int i=1; i<=n; i++){
		if (dp1[i]+dp2[i]<ans+1) out[i]=1;
		else cnt[dp1[i]]++;
	}
	for (int i=1; i<=n; i++){
		if (out[i]==1) continue;
		if (cnt[dp1[i]]==1) out[i]=3;
		else out[i]=2;
	}
	for (int i=1; i<=n; i++) cout<<out[i];
	cout<<endl;
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