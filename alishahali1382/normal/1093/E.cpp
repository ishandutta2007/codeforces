#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define low(x) (x&(-x))

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 200460;

int n, m, x, y, t, a, b, ans, typ, l1, r1, l2, r2;
int A[MAXN], tmp[MAXN];

ordered_set<int> BIT[MAXN];

void add(int ind, int x){
	for (int i=ind; i<MAXN; i+=low(i)) BIT[i].insert(x);
}
void rem(int ind, int x){
	for (int i=ind; i<MAXN; i+=low(i)) BIT[i].erase(x);
}
int query(int x, int ind){
	int res=0;
	for (int i=ind; i; i-=low(i)) res+=BIT[i].order_of_key(x+1);
	//cerr<<"query "<<ind<<' '<<x<<' '<<res<<endl;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>x;
		tmp[x]=i;
	}
	for (int i=1; i<=n; i++){
		cin>>x;
		A[i]=tmp[x];
	}
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	for (int i=1; i<=n; i++) add(i, A[i]);
	while (m--){
		cin>>typ;
		if (typ==1){
			cin>>l1>>r1>>l2>>r2;
			ans=query(r1, r2);
			ans-=query(r1, l2-1)+query(l1-1, r2);
			ans+=query(l1-1, l2-1);
			cout<<ans<<'\n';
			continue ;
		}
		cin>>a>>b;
		rem(a, A[a]);
		rem(b, A[b]);
		swap(A[a], A[b]);
		add(a, A[a]);
		add(b, A[b]);
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