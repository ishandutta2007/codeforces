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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[251][251][251];
int sz[3];
vector<char> vec[3];
vector<int> pos[26];

string s;
char ch;

void print(){
	if (dp[sz[0]][sz[1]][sz[2]]<=n) cout<<"YES\n";
	else cout<<"NO\n";
}

int find_ch(int l, char c){
	//if (l>=n) return l;
	return *upper_bound(all(pos[c-'a']), l);
}

void update(int sz0, int sz1, int sz2){
	dp[sz0][sz1][sz2]=n+1;
	//dp[0][0][0]=0;
	if (sz0) dp[sz0][sz1][sz2]=min(dp[sz0][sz1][sz2], find_ch(dp[sz0-1][sz1][sz2], vec[0][sz0-1]));
	//debug("0")
	
	if (sz1) dp[sz0][sz1][sz2]=min(dp[sz0][sz1][sz2], find_ch(dp[sz0][sz1-1][sz2], vec[1][sz1-1]));
	//debug("1")
	
	if (sz2) dp[sz0][sz1][sz2]=min(dp[sz0][sz1][sz2], find_ch(dp[sz0][sz1][sz2-1], vec[2][sz2-1]));
	//debug("2")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>s;
	s="."+s;
	for (int i=1; i<=n; i++) pos[s[i]-'a'].pb(i);
	for (int i=0; i<26; i++) pos[i].pb(inf);
	memset(dp, 31, sizeof(dp));
	dp[0][0][0]=0;
	while (m--){
		cin>>ch;
		if (ch=='-'){
			cin>>x;
			x--;
			vec[x].pop_back();
			sz[x]--;
			print();
			continue ;
		}
		cin>>x>>ch;
		x--;
		vec[x].pb(ch);
		sz[x]++;
		
		if (x==0) for (int sz1=0; sz1<=sz[1]; sz1++) for (int sz2=0; sz2<=sz[2]; sz2++) update(sz[0], sz1, sz2);
		if (x==1) for (int sz0=0; sz0<=sz[0]; sz0++) for (int sz2=0; sz2<=sz[2]; sz2++) update(sz0, sz[1], sz2);
		if (x==2) for (int sz0=0; sz0<=sz[0]; sz0++) for (int sz1=0; sz1<=sz[1]; sz1++) update(sz0, sz1, sz[2]);
		
		
		print();
		/*
		cerr<<endl;
		debugv(vec[0])
		debugv(vec[1])
		debugv(vec[2])
		debug(sz[0])
		debug(dp[sz[0]][sz[1]][sz[2]])
		cerr<<endl;*/
	}/*
	debug(dp[3][2][2])
	debug2(dp[2][2][2], find_ch(dp[2][2][2], vec[0][2]))
	debug2(dp[3][1][2], find_ch(dp[3][1][2], vec[1][1]))
	debug2(dp[3][2][1], find_ch(dp[3][2][1], vec[2][1]))
	
	debug2(dp[2][2][1], find_ch(dp[2][2][1], vec[0][2]))
	debug2(dp[3][1][1], find_ch(dp[3][1][1], vec[1][1]))
	debug2(dp[3][2][0], find_ch(dp[3][2][0], vec[2][0]))
	*/
	return 0;
}
/*
6 7
abdabc
+ 1 a
+ 1 d
+ 2 b
+ 2 c
+ 3 a
+ 3 b
+ 1 c

*/
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