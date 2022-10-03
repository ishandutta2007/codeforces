#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 2000010;

int n, m, u, v, x, y, t, a, b, ans, cnt;
int A[MAXN];
int sieve[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) sieve[i]=i;
	for (int i=2; i*i<MAXN; i++){
		if (sieve[i]!=i) continue ;
		for (int j=i*i; j<MAXN; j+=i) sieve[j]=i;
	}
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		if (A[i]==1) cnt++;
	}
	if (cnt){
		for (int i=0; i<n; i++){
			if (A[i]==1) continue ;
			if (sieve[A[i]+1]==A[i]+1){
				cout<<cnt+1<<endl<<A[i];
				while (cnt--) cout<<" 1";
				cout<<endl;
				return 0;
			}
		}
	}
	if (cnt>=2){
		cout<<cnt<<endl;
		while (cnt--) cout<<"1 ";
		cout<<endl;
		return 0;
	}
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++){
		if (sieve[A[i]+A[j]]==A[i]+A[j]){
			cout<<"2\n";
			cout<<A[i]<<' '<<A[j]<<endl;
			return 0;
		}
	}
	cout<<"1\n"<<A[0]<<endl;
	
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