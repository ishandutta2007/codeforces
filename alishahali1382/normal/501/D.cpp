#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[2][MAXN];
int B[MAXN];
int ans[MAXN];
int fen[MAXN];
ordered_set<int> st;

void add(int pos, int x){ for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;}
int get(int x){
	int res=0;
	for (; x; x-=x&-x) res+=fen[x];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<2; i++) for (int j=1; j<=n; j++) cin>>A[i][j], A[i][j]++;
	
	for (int j=0; j<2; j++){
		for (int i=1; i<=n; i++){
			int tmp=A[j][i]-get(A[j][i])-1;
			B[i]+=tmp;
			add(A[j][i], 1);
		}
		//for (int i=1; i<n; i++) cerr<<B[i]<<" \n"[i==n-1];
		memset(fen, 0, sizeof(fen));
	}
	for (int i=n-1; i; i--) if (B[i]>n-i){
		B[i]-=n-i+1;
		B[i-1]++;
	}
	//for (int i=0; i<n; i++) cerr<<B[i]<<" \n"[i==n-1];
	for (int i=0; i<n; i++) st.insert(i);
	
	for (int i=1; i<=n; i++){
		int tmp=*st.find_by_order(B[i]);
		cout<<tmp<<' ';
		st.erase(tmp);
		//debugv(st)
	}
	
	return 0;
}