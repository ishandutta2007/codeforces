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
const int MAXN = 500010, SQ=1000, CNT=MAXN/SQ+2;

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
int lazy[CNT];
unordered_map<int, int> L[CNT], R[CNT];

void recalc(int id){
	int le=min(id*SQ, n+1), ri=min(n+1, le+SQ);
	L[id].clear();
	R[id].clear();
	for (int i=le; i<ri; i++){
		A[i]+=lazy[id];
		if (A[i]>=inf) A[i]=inf;
		if (A[i]==inf) continue ;
		R[id][A[i]]=i;
		if (!L[id].count(A[i])) L[id][A[i]]=i;
	}
	lazy[id]=0;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%d", A+i);
	for (int i=0; i<CNT; i++) recalc(i);
	while (m--){
		scanf("%ld", &t);
		if (t==1){
			scanf("%d%d%d", &l, &r, &x);
			if (!x) continue; // tof
			int idl=l/SQ, idr=r/SQ;
			r++;
			while (l<r){
				if (l%SQ==0 && l+SQ<=r){
					if ((lazy[l/SQ]+=x)>=inf) lazy[l/SQ]=inf;
					l+=SQ;
				}
				else{
					if ((A[l]+=x)>=inf) A[l]=inf;
					l++;
				}
			}
			recalc(idl);
			recalc(idr);
			continue ;
		}
		scanf("%d", &y);
		l=1, r=0;
		for (int id=0; id<CNT; id++) if (L[id].count(y-lazy[id])){
			l=L[id][y-lazy[id]];
			break ;
		}
		for (int id=CNT-1; id>=0; id--) if (R[id].count(y-lazy[id])){
			r=R[id][y-lazy[id]];
			break ;
		}
		printf("%d\n", r-l);
	}
	
	return 0;
}