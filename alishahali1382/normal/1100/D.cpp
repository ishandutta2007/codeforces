#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> edge;
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
const int MAXN = 670;

int n, m, k, u, v, x, y, xx, yy, t, a, b, ans;
int X[MAXN];
int Y[MAXN];
int cnt[4];
set<pii> st;

void out(int xx, int yy){
	if (st.count({xx, yy})){
		if (x!=xx) out(x, yy);
		else out(yy, x);
		return ; 
	}
	x=xx;
	y=yy;
	cout<<xx<<' '<<yy<<'\n';
	cout.flush();
}

void inp(){
	cin>>k>>xx>>yy;
	if (k==-1 || !k) exit(0);
	st.erase({X[k], Y[k]});
	X[k]=xx;
	Y[k]=yy;
	st.insert({X[k], Y[k]});
	return ;
}

void go(int dx, int dy){
	//cerr<<"go "<<dx<<' '<<dy<<endl;
	while (x!=dx || y!=dy){
		xx=x;
		yy=y;
		if (xx<dx) xx++;
		if (xx>dx) xx--;
		if (yy<dy) yy++;
		if (yy>dy) yy--;
		out(xx, yy);
		inp();
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>x>>y;
	for (int i=1; i<=666; i++) cin>>X[i]>>Y[i], st.insert({X[i], Y[i]});
	go(500, 500);
	for (int i=1; i<=666; i++){
		if (X[i]<500 && Y[i]<500) cnt[0]++;
		if (X[i]<500 && Y[i]>500) cnt[1]++;
		if (X[i]>500 && Y[i]<500) cnt[2]++;
		if (X[i]>500 && Y[i]>500) cnt[3]++;
	}
	if (cnt[0]<=166) go(999, 999);
	if (cnt[1]<=166) go(999, 1);
	if (cnt[2]<=166) go(1, 999);
	if (cnt[3]<=166) go(1, 1);
	
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