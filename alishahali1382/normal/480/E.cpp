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
const int MAXN = 2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];
int X[MAXN], Y[MAXN], out[MAXN];
int L[MAXN][MAXN];
int R[MAXN][MAXN];
char ch;

void process(int i){
	for (int j=1; j<=m; j++){
		L[i][j]=max(L[i][j-1], 1);
		if (A[i][j]) L[i][j]=j+1;
	}
	R[i][m]=m+1;
	if (A[i][m]) R[i][m]=m;
	for (int j=m-1; j; j--){
		R[i][j]=R[i][j+1];
		if (A[i][j]) R[i][j]=j;
	}
}

void go_col(int y){
	deque<int> dl, dr;
	for (int i=1, j=1; i<=n; i++){
		while (dl.size() && L[dl.front()][y]<L[i][y]) dl.pop_front();
		dl.push_front(i);
		while (dr.size() && R[dr.front()][y]>R[i][y]) dr.pop_front();
		dr.push_front(i);
		
		while (j<i && R[dr.back()][y]-L[dl.back()][y]<i-j+1){
			if (dr.back()<=j) dr.pop_back();
			if (dl.back()<=j) dl.pop_back();
			j++;
		}
		ans=max(ans, min(i-j+1, R[dr.back()][y]-L[dl.back()][y]));	
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>ch;
		A[i][j]=(ch=='X');
	}
	for (int i=1; i<=k; i++){
		cin>>X[i]>>Y[i];
		A[X[i]][Y[i]]=1;
	}
	
	for (int i=1; i<=n; i++) process(i);
	for (int i=1; i<=m; i++) go_col(i);
	
	for (int i=k; i; i--){
		out[i]=ans;
		A[X[i]][Y[i]]=0;
		process(X[i]);
		go_col(Y[i]);
	}
	for (int i=1; i<=k; i++) cout<<out[i]<<'\n';
		
	return 0;
}