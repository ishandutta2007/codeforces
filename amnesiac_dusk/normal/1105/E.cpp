/*
 * 	Just close your eyes
 * 		The sun is going down
 * 			You'll be alright...
 * 				No one can hurt you now
 * 					Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<size_t max_n>
class Clique{
using bits = bitset<max_n>;
bits MASK,ZERO,ans;
const bits *e;
int N;
// int64_t calls;
void bk_init(){
ans=ZERO;
MASK=ZERO;
MASK.flip();
//calls = 0;
}
void bk(bits use, bits can_start,bits can_other){
// ++calls;
if(can_start.none()&&can_other.none()){
if(use.count()>ans.count())ans=use;
return;
}
bits r=can_start;
bool fi=1;
for(int i=0;i<N;++i){
if(r[i]){
if(fi){
fi=0;
r&=e[i]^MASK;
}
use[i]=1;
bk(use,can_start&e[i],can_other&e[i]);
use[i]=0;
can_start[i]=0;
can_other[i]=1;
}
}
}
static Clique& get(){
static Clique c;
return c;
}
public:
static bits find_clique(bits const*g, const int&n){
Clique& c = get();
c.e = g;
c.N = n;
c.bk_init();
bits me;
c.bk(me,c.MASK,c.ZERO);
// cerr << "Calls: " << c.calls << "\n";
// c.calls = 0;
return c.ans;
}
static bits find_clique(vector<bits> const&g){
return find_clique(g.data(), g.size());
}
static bits find_clique(array<bits, max_n> const&g,
const int&n){
return find_clique(g.data(), n);
}
};

vector<bitset<55>> gg(55);
map<string,int> num;
vector<int> lol;
bool g[55][55];
void solve() {
	int n,m;
	cin>>n>>m;
	int cc = 0;
	fr(i, 1, n){
		int t;
		cin >> t;
		if(t == 1){
			sort(all(lol));
			unique(all(lol));
			for(int x : lol){
				for(int y : lol){
					g[x][y] = 1;
				}
			}
			lol.clear();
		}
		else{
			string s;
			cin >> s;
			if(!num.count(s))
				num[s] = ++cc;
			lol.pb(num[s]);
		}
	}
	sort(all(lol));
	unique(all(lol));
	for(int x : lol){
		for(int y : lol){
			g[x][y] = 1;
		}
	}
	lol.clear();
	fr(i, 1, cc){
		fr(j, 1, cc){
			gg[i - 1][j - 1] = !g[i][j];
		}
	}
	Clique<55> cl;
	cout << cl.find_clique(gg).count();
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}