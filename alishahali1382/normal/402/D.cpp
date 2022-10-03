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
const int MAXN = 5010;

int n, m, ans;
int A[MAXN];
int B[MAXN];
int dp[MAXN];
bool sieve[40000];
int prime[10000], cnt;
int good[10000];

int f(int x){
	int res=0;
	for (int i=0; i<cnt && prime[i]<=x;){
		if (x%prime[i]){
			i++;
			continue ;
		}
		res+=good[i];
		x/=prime[i];
	}
	if (x!=1){
		if (*lower_bound(B, B+m, x)==x) res--;
		else res++;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<40000; i++){
		if (sieve[i]) continue ;
		for (int j=i*i; j<40000; j+=i) sieve[j]=true;
	}
	for (int i=2; i<40000; i++) if (!sieve[i]) prime[cnt++]=i;
	//debug(cnt);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		dp[i]=__gcd(dp[i-1], A[i]);
	}
	for (int i=0; i<m; i++) cin>>B[i];
	
	for (int i=0; i<cnt; i++){
		good[i]=1;
		if ((*lower_bound(B, B+m, prime[i]))==prime[i]) good[i]=-1;
	}
	
	ll x=1;
	for (int i=n; i; i--){
		dp[i]/=x;
		A[i]/=x;
		if (f(dp[i])<=0){
			A[i]/=dp[i];
			x*=dp[i];
		}
	}
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++) ans+=f(A[i]);
	cout<<ans<<endl;
	
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