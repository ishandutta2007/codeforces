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
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, d, ans;
int A[MAXN];
int ind[MAXN];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n;
	if (n<=60){
		for (int i=1; i<=n; i++){
			cout<<"? "<<i<<'\n';
			cout.flush();
			cin>>A[i];
		}
		sort(A+1, A+n+1);
		cout<<"! "<<A[1]<<' '<<A[2]-A[1]<<endl;
		return 0;
	}
	for (int i=1; i<n; i++) ind[i]=i;
	shuffle(ind+1, ind+n, rng);
	int dwn=0, up=1e9+1;
	while (up-dwn>1){
		int mid=(dwn+up)/2;
		cout<<"> "<<mid<<endl;
		cout.flush();
		cin>>x;
		if (x) dwn=mid;
		else up=mid;
	}
	A[n]=up;
	for (int i=1; i<=30; i++){
		cout<<"? "<<ind[i]<<'\n';
		cout.flush();
		cin>>A[i];
	}
	for (int i=1; i<=30; i++) for (int j=i+1; j<=30; j++) d=__gcd(d, abs(A[i]-A[j]));
	for (int i=1; i<=30; i++) d=__gcd(d, abs(A[i]-A[n]));
	for (int i=1; i*i<=d; i++){
		if (A[n]-(n-1)*(d/i)>=0){
			cout<<"! "<<A[n]-(n-1)*d<<' '<<d<<endl;
			return 0;
		}
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