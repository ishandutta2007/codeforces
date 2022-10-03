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
const int MAXN = 3010;

struct state{
	int x, y;
};

int n, m, k, u, v, t, a, b, ans;
int P[MAXN];
int dist[MAXN][MAXN];
queue<state> q;

vector<state> valid(state st){
	vector<state> out;
	int x=st.x, y=st.y;
	if (x==y) return out;
	if (y<=a && P[x]!=100) out.pb({y, y+1});
	if (b<y && P[x]) out.pb({x, y+1});
	if (y<=a && P[x]) out.pb({y+1, y+2});
	
	return out;
}

void bfs(){
	dist[1][2]=0;
	q.push({1, 2});
	while (!q.empty()){
		state st=q.front();
		q.pop();
		if (st.x>n || st.y>n) continue ;
		if (dist[st.x][st.y]>k) return ;
		//cerr<<"state : "<<st.x<<' '<<st.y<<endl;
		if (!st.x && !st.y) continue ;
		for (state s:valid(st)){
			if (s.x>n) s.x=s.y=0;
			if (s.y>n) s.y=s.x;
			if (dist[st.x][st.y]+1<dist[s.x][s.y]){
				dist[s.x][s.y]=dist[st.x][st.y]+1;
				q.push(s);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 31, sizeof(dist));
	cin>>n>>k;
	if (n==1) kill(1);
	for (int i=1; i<=n; i++){
		cin>>P[i];
		if (P[i]) a=i;
		if (P[i]==100) b=i;
	}
	bfs();
	ans=(dist[0][0]<=k);
	for (int i=1; i<=n; i++) for (int j=i; j<=n; j++) ans+=(dist[i][j]<=k);
	cout<<ans<<'\n';
	
	
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