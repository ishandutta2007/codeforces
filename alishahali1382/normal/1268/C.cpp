#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
int A[MAXN], B[MAXN];
int fen[MAXN];
ll ans[MAXN];
ordered_set<int> shit;

void add(int pos, int x){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		B[A[i]]=i;
	}
	for (int i=1; i<=n; i++){
		ans[i]=ans[i-1] + i-1-get(B[i]);
		add(B[i], +1);
	}
	
	ll res=0;
	memset(fen, 0, sizeof(fen));
	for (int i=1; i<=n; i++) add(i, +1);
	shit.insert(B[1]);
	add(B[1], -1);
	int cent=B[1];
	for (int i=2; i<=n; i++){
		int pos=B[i];
		
		if (pos<cent) res+=get(cent)-get(pos);
		else res+=get(pos-1)-get(cent);
		
		if (pos<cent) res-=pos-1-get(pos-1);
		else res-=(n-pos)-(get(n)-get(pos));
		add(pos, -1);
		
		shit.insert(pos);
		int tmp=*shit.find_by_order(i/2);
		
		if (tmp!=cent){
			//debug2(cent, tmp)
			//debug(res)
			if (tmp>cent){
				res+=1ll*(cent-get(cent))*(tmp-cent-1);
				res-=1ll*(n-(tmp-1) - (get(n)-get(tmp-1)))*(tmp-cent-1);
			}
			else{
				res-=1ll*(tmp-get(tmp))*(cent-tmp-1);
				res+=1ll*(n-(cent-1) - (get(n)-get(cent-1)))*(cent-tmp-1);
			}
			//debug(res)
			cent=tmp;
		}
		//debug2(i, res)
		
		ans[i]+=res;
	}
	
	
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
	
	return 0;
}