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
int A[MAXN];
set<int> mark, in;
vector<int> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	out.pb(0);
	for (int i=1; i<=n; i++){
		bool f=0;
		if (A[i]>0){
			if (in.count(A[i])) kill(-1)
			if (mark.count(A[i])) f=1;
			else{
				mark.insert(A[i]);
				in.insert(A[i]);
			}
		}
		else{
			if (!in.count(-A[i])) kill(-1)
			else{
				in.erase(-A[i]);
			}
		}
		if (f || i==n || in.empty()){
			if (in.size()) kill(-1)
			out.pb(i);
			mark.clear();
			in.clear();
			//debug(i)
		}
	}
	cout<<out.size()-1<<'\n';
	for (int i=1; i<out.size(); i++) cout<<out[i]-out[i-1]<<' ';
	
	return 0;
}