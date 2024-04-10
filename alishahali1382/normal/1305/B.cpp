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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool dead[MAXN];
string A;
vector<vector<int>> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>A;
	n=A.size();
	while (1){
		int i=0, j=n-1;
		vector<int> v1, v2;
		while (i<j){	
			while (i<j && (A[i]==')' || dead[i])) i++;
			while (i<j && (A[j]=='(' || dead[j])) j--;
			if (i>=j || A[i]==')' || A[j]=='(') break ;
			v1.pb(i++);
			v2.pb(j--);
		}
		if (v1.empty()) break ;
		reverse(all(v2));
		for (int i:v2) v1.pb(i);
		for (int i:v1) dead[i]=1;
		out.pb(v1);
	}
	
	cout<<out.size()<<'\n';
	for (auto vec:out){
		cout<<vec.size()<<'\n';
		for (int i:vec) cout<<i+1<<' ';cout<<'\n';
	}
	
	return 0;
}