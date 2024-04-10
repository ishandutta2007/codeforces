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
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 600010, LOG=18;

pll Bezo(ll x, ll y){
	if (!y) return {1, 0};
	pll p=Bezo(y, x%y);
	return {p.second, p.first-p.second*(x/y)};
}

pll CRT(pll p1, pll p2){
	ll n1=p1.first, a1=p1.second, n2=p2.first, a2=p2.second;
	if (!n1 || !n2) return {0, 0};
	pll p=Bezo(n1, n2);
	ll d=__gcd(n1, n2), lcm=n1/d*n2;
	if (abs(a1-a2)%d) return {0, 0};
	return {lcm, (((a2-a1)/d*p.first%(n2/d))*n1+a1)%lcm};
}

ll n, m, u, v, x, y, t, a, b;
int k[MAXN];
pll table[MAXN][LOG];
vector<pii> vec[MAXN];

bool valid(int l, int r){ // [l, r)
	int x=log2(r-l);
	return CRT(table[l][x], table[r-(1<<x)][x]).first!=0;
}

int calc(vector<pii> &vec, int l, int r){ // [l, r)
	for (int i=l; i<r; i++) table[vec[i].first][0]={k[vec[i].first], vec[i].second};
	l=vec[l].first;
	r=vec[r-1].first;
	for (int j=1; j<LOG; j++) for (int i=l; i<=r; i++) table[i][j]=CRT(table[i][j-1], table[i+(1<<(j-1))][j-1]);
	
	int res=0;
	for (int i=l, j=l; i<=r; i++){
		while (!valid(j, i+1)) j++;
		res=max(res, i-j+1);
	}
	for (int j=0; j<LOG; j++) for (int i=l; i<=r; i++) table[i][j]={0, 0};
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>k[i];
		for (int j=0; j<k[i]; j++){
			cin>>x;
			vec[x].pb({i, j});
		}
	}
	for (int i=1; i<=m; i++){
		if (vec[i].empty()){
			cout<<"0\n";
			continue ;
		}
		int ans=0, l=0;
		for (int j=1; j<vec[i].size(); j++){
			if (vec[i][j-1].first+1==vec[i][j].first) continue;
			else{
				ans=max(ans, calc(vec[i], l, j));
				l=j;
			}
		}
		ans=max(ans, calc(vec[i], l, vec[i].size()));
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/