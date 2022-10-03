#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 300010;

bool cmp(pii a, pii b){
	return a.first-a.second<b.first-b.second;
}

ll n, m, x, a, b;
ll ans[MAXN];
ll A[MAXN];
ll B[MAXN];
pii C[MAXN];
ll D[MAXN];
ll psl[MAXN];
ll psr[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>B[i];
		C[i]={A[i],B[i]};
	}
	sort(C+1, C+n+1, cmp);
	for (int i=1; i<=n; i++) D[i]=C[i].first-C[i].second;
	for (int i=1; i<=n; i++) psl[i]=psl[i-1]+C[i].first;
	for (int i=n; i; i--) psr[i]=psr[i+1]+C[i].second;
	
	for (int i=1; i<=n; i++){
		int x=lower_bound(D+1, D+n+1, A[i]-B[i])-D;
		//cerr<<i<<' '<<x<<endl;
		ans[i]=psl[x]+psr[x+1]+(x)*B[i]+(n-x)*A[i];
		ans[i]-=A[i]+B[i];
	}
	while (m--){
		cin>>a>>b;
		int x=min(A[a]+B[b], A[b]+B[a]);
		ans[a]-=x;
		ans[b]-=x;
	}
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}
/*
3 0
1 2
2 3
1 3
*/


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