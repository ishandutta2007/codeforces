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
const int MAXN = 100010, SQ=1500, MOSQ=330;

int n, q, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN], cnt[MAXN], C[MAXN];
int Q[MAXN], L[MAXN], R[MAXN], LSQ[MAXN];
ll ans[MAXN];
vector<int> big;
priority_queue<int, vector<int>, greater<int>> pq;

bool MO(int i, int j){
	if (LSQ[i]!=LSQ[j]) return LSQ[i]<LSQ[j];
	if (LSQ[i]&1) return R[i]<R[j];
	return R[i]>R[j];
}

void add(int x){
	cnt[B[x]]--;
	B[x]++;
	cnt[B[x]]++;
}

void rem(int x){
	cnt[B[x]]--;
	B[x]--;
	cnt[B[x]]++;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], B[A[i]]++;
	for (int i=1; i<MAXN; i++){
		if (B[i]>SQ) big.pb(i);
		B[i]=0;
	}
	cin>>q;
	for (int i=1; i<=q; i++){
		cin>>L[i]>>R[i];
		LSQ[i]=L[i]/MOSQ;
		Q[i]=i;
		R[i]++;
	}
	sort(Q+1, Q+q+1, MO);
	int ml=1, mr=1;
	for (int _=1; _<=q; _++){
		int id=Q[_], l=L[id], r=R[id];
		while (l<ml) add(A[--ml]);
		while (mr<r) add(A[mr++]);
		while (ml<l) rem(A[ml++]);
		while (r<mr) rem(A[--mr]);
		
		while (pq.size()) pq.pop();
		for (int i=1; i<=SQ; i++) C[i]=cnt[i];
		for (int i:big) if (B[i]>SQ) pq.push(B[i]);
		
		int x=-1;
		for (int i=1; i<=SQ; i++) if (C[i]){
			if (x!=-1){
				x+=i;
				C[i]--;
				ans[id]+=x;
				if (x<=SQ) C[x]++;
				else pq.push(x);
				x=-1;
			}
			if (C[i]&1) x=i, C[i]--;
			if (!C[i]) continue ;
			C[i]>>=1;
			ans[id]+=2ll*i*C[i];
			if (2*i<=SQ) C[2*i]+=C[i];
			else{
				while (C[i]--) pq.push(2*i);
			}
			C[i]=0;
		}
		if (x!=-1) pq.push(x);
		
		while (pq.size()>1){
			int x=pq.top();
			pq.pop();
			x+=pq.top();
			pq.pop();
			ans[id]+=x;
			pq.push(x);
		}
	}
	for (int i=1; i<=q; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
7
1 2 1 3 1 2 1
2
1 7
2 4

*/