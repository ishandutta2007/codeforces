#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

struct Node{
	int abc, ab, bc, a, b, c;
	Node(){
		abc=ab=bc=a=b=c=0;
	}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
string S;

Node Merge(Node X, Node Y){
	Node Z;
	Z.abc=X.abc+Y.abc;
	int t=min(X.ab, Y.c);
	Z.abc+=t, X.ab-=t, Y.c-=t;
	t=min(X.a, Y.bc);
	Z.abc+=t, X.a-=t, Y.bc-=t;
	t=min(X.ab, Y.bc);
	Z.abc+=t, X.ab-=t, Y.bc-=t, Z.b+=t;
	Z.ab=X.ab+Y.ab;
	t=min(X.a, Y.b);
	Z.ab+=t, X.a-=t, Y.b-=t;
	Z.bc=X.bc+Y.bc;
	t=min(X.b, Y.c);
	Z.bc+=t, X.b-=t, Y.c-=t;
	Z.a+=X.a+Y.a;
	Z.b+=X.b+Y.b;
	Z.c+=X.c+Y.c;
	return Z;
}
void Set(int id, int tl, int tr, int pos, char val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]=seg[0];
		seg[id].a+=(val=='a');
		seg[id].b+=(val=='b');
		seg[id].c+=(val=='c');
		return ;
	}
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>S;
	for (int i=0; i<n; i++) Set(1, 0, n, i, S[i]);
	while (m--){
		cin>>x;
		x--;
		cin>>S[x];
		Set(1, 0, n, x, S[x]);
		cout<<seg[1].abc<<"\n";
	}
	
	return 0;
}