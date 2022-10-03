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
const int MAXN = 300010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int cnt[3];
char ch;

void print(){
	for (int i=0; i<n; i++) cout<<A[i];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>ch;
		A[i]=ch-'0';
		cnt[A[i]]++;
	}
	if (cnt[0]==cnt[1] && cnt[1]==cnt[2]){
		print();
		return 0;
	}
	for (int i=0; i<n; i++){
		if (cnt[0]<n/3 && cnt[A[i]]>n/3){
			cnt[0]++;
			cnt[A[i]]--;
			A[i]=0;
			continue ;
		}
	}
	//-------------------------------------------
	//-------------------------------------------
	for (int i=0; i<n; i++){
		if (cnt[1]<n/3 && A[i]==2 && cnt[2]>n/3){
			cnt[1]++;
			cnt[2]--;
			A[i]=1;
			continue ;
		}
	}
	//-------------------------------------------
	for (int i=n-1; i>=0; i--){
		if (cnt[2]<n/3 && A[i]==1 && cnt[1]>n/3){
			cnt[2]++;
			cnt[1]--;
			A[i]=2;
			continue ;
		}
	}
	//-------------------------------------------
	for (int i=n-1; i>=0; i--){
		if (cnt[2]<n/3 && A[i]==0 && cnt[0]>n/3){
			cnt[2]++;
			cnt[0]--;
			A[i]=2;
			continue ;
		}
	}
	//-------------------------------------------
	for (int i=n-1; i>=0; i--){
		if (cnt[1]<n/3 && A[i]==0 && cnt[0]>n/3){
			cnt[1]++;
			cnt[0]--;
			A[i]=1;
			continue ;
		}
	}
	//-------------------------------------------
	print();
	
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