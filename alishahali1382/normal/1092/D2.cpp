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
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010;

int n, m, u, v, x, y, t, a, b, ans, cnt, mx;
int A[MAXN];
int mn[MAXN];
stack<int> st;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;/*
	for (int i=1; i<=n; i++){
		cin>>A[i];
		mx=max(mx, A[i]);
		if (A[i]%2){
			if (i%2) cnt--;
			else cnt++;
		}
	}
	//debug(cnt);
	if (cnt && (n%2)==0 || abs(cnt)>1 && n%2 && mx%2) kill("NO");*/
	//-------------------------------------------------------------
	for (int i=1; i<=n; i++) cin>>A[i];
	//debug("survive");
	A[0]=inf;
	st.push(0);
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++){
		while (A[st.top()]<A[i]) /*cerr<<st.top()<<' '<<i<<endl, */st.pop();
		mn[i]=st.top();
		st.push(i);
	}
	//for (int i=1; i<=n; i++) cerr<<mn[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++) if ((i-mn[i]+1)%2) kill("NO");
	reverse(A+1, A+n+1);
	st.push(0);
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++){
		while (A[st.top()]<A[i]) /*cerr<<st.top()<<' '<<i<<endl, */st.pop();
		mn[i]=st.top();
		st.push(i);
	}
	for (int i=1; i<=n; i++) if ((i-mn[i]+1)%2) kill("NO");
	
	cout<<"YES"<<endl;
	
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