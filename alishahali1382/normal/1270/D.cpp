#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
int A[MAXN];
set<int> s1, s2, shit;

void ask(set<int> &S){
	cout<<"? ";
	for (int x:S) cout<<x<<' ';
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=k+1; i++) shit.insert(i);
	for (int i=1; i<=k; i++) s1.insert(i);	
	ask(s1);
	int pos1, pos2, a1, a2;
	cin>>pos1>>a1;
	for (int i=1; i<=k+1; i++) if (i!=pos1) s2.insert(i);
	ask(s2);
	cin>>pos2>>a2;
	
	for (int p:s2) if (p!=pos2){
		shit.erase(p);
		ask(shit);
		shit.insert(p);
		int pos3, a3;
		cin>>pos3>>a3;
		if (a1<a2) ans+=(pos2==pos3);
		else ans+=(pos2!=pos3);
	}
	cout<<"! "<<ans+1<<endl;
	return 0;
}