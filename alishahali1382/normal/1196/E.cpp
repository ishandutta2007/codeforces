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

int b, w, Y, k, u, v, x, y, t, a, ans;

int solve(){
	cin>>b>>w;
	if (b>w) swap(b, w), Y=2;
	else Y=3;
	if (w>3*b+1) kill("NO")
	cout<<"YES\n";
	for (int i=0; i<2*b-1; i++) cout<<2+i<<' '<<Y<<'\n';
	w-=b-1;
	if (w) cout<<"1 "<<Y<<'\n', w--;
	if (w) cout<<2*b+1<<' '<<Y<<'\n', w--;
	for (int i=2; i<=2*b && w; i+=2, w--) cout<<i<<' '<<Y-1<<'\n';
	for (int i=2; i<=2*b && w; i+=2, w--) cout<<i<<' '<<Y+1<<'\n'; 
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	while (T--) solve();
	
	
	
	return 0;
}