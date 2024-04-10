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
const int inf=1e9+100;
const int mod = 1000000007;
const int MAXN = 510;

int n, m, x, y, ans=inf;
int dp[MAXN][26][26];
pii upd[MAXN][26][26];
int A[MAXN][MAXN];
char ch;

void print(pii p){
	int a=p.first;
	int b=p.second;
	for (int i=0; i<m; i++){
		if (i%2) cout<<(char)('a'+b);
		else cout<<(char)('a'+a);
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, 63, sizeof(dp));
	for (int i=0; i<26; i++) for (int j=0; j<26; j++) if (i!=j) dp[0][i][j]=0;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin>>ch;
			A[i][j]=ch-'a';
		}
		for (int a=0; a<26; a++){
			for (int b=0; b<26; b++){
				if (a==b) continue ;
				int tmp=0;
				for (int j=1; j<=m; j+=2) if (a!=A[i][j]) tmp++;
				for (int j=2; j<=m; j+=2) if (b!=A[i][j]) tmp++;
				for (int aa=0; aa<26; aa++){
					if (a==aa) continue ;
					for (int bb=0; bb<26; bb++){
						if (b==bb) continue ;
						if (tmp+dp[i-1][aa][bb]<dp[i][a][b]){
							upd[i][a][b]={aa, bb};
							dp[i][a][b]=tmp+dp[i-1][aa][bb];
						}
					}
				}
			}
		}
	}
	int a=0, b=0;
	for (int i=0; i<26; i++){
		for (int j=0; j<26; j++){
			if (dp[n][i][j]<dp[n][a][b]){
				a=i;
				b=j;
			}
		}
	}
	cout<<dp[n][a][b]<<endl;
	stack<pii> st;
	for (int i=n; i; i--){
		st.push({a, b});
		int tmp=a;
		a=upd[i][a][b].first;
		b=upd[i][tmp][b].second;
	}
	while (!st.empty()){
		print(st.top());
		st.pop();
	}
	
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