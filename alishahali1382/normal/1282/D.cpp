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

int n, m, k, u, v, x, y, t, a, b;
string ans;

int ask(){
	int x;
	cin>>x;
	if (!x) exit(0);
	assert(x!=-1);
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<300; i++) cout<<'a';cout<<endl;
	a=300-ask();
	for (int i=0; i<300; i++) cout<<'b';cout<<endl;
	b=300-ask();
	n=a+b;
	int shit=n-a;
	for (int i=0; i<n-1; i++){
		for (int j=0; j<n; j++) cout<<(char)('a'+(i==j));cout<<endl;
		x=ask();
		if (x<shit){
			ans+='b';
			b--;
		}
		else{
			ans+='a';
			a--;
		}
	}
	ans+=(char)('a'+b);
	cout<<ans<<endl;
	ask();
	assert(0);
	
	return 0;
}