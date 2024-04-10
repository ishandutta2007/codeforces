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

const ld PI=acos(-1);
const ld eps=1e-6;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 310, LOG=20;

ll n, m, k, t, a, b, ans;
ld ang[MAXN][MAXN];
ld X[MAXN], Y[MAXN];
ll dp[MAXN][MAXN][6];
pii A[MAXN*MAXN];

int f(ld x, ld y){
	if (abs(y)<eps){
		if (x>0) return 0;
		return 2;
	}
	if (y>0) return 1;
	return 2;
}

bool cmp(pii i, pii j){
	ld a1=ang[i.first][i.second], a2=ang[j.first][j.second];
	ld x1=X[i.second]-X[i.first], y1=Y[i.second]-Y[i.first];
	ld x2=X[j.second]-X[j.first], y2=Y[j.second]-Y[j.first];
	int f1=f(x1, y1), f2=f(x2, y2);
	if (f1!=f2) return f1<f2;
	return y1*x2<y2*x1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>X[i]>>Y[i];
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (i!=j){
		ld x=X[j]-X[i], y=Y[j]-Y[i];
		ld z=sqrt(x*x+y*y);
		ld sn=y/z;
		ld theta=asin(sn)*180/PI;
		//if (theta<0) theta+=360;
		ang[i][j]=theta;
		A[++t]={i, j};
	}
	sort(A+1, A+t+1, cmp);
	for (int i=0; i<n; i++) dp[i][i][0]=1;
	for (int e=1; e<=t; e++){
		int u=A[e].first, v=A[e].second;
		//debug(ang[u][v])
		for (int cnt=1; cnt<=5; cnt++) for (int i=0; i<n; i++) dp[i][v][cnt]+=dp[i][u][cnt-1];
	}
	for (int i=0; i<n; i++) ans+=dp[i][i][5];
	cout<<ans<<'\n';
	
	return 0;
}
/*
10
841746 527518
595261 331297
-946901 129987
670374 -140388
-684770 309555
-302589 415564
-387435 613331
-624940 -95922
945847 -199224
24636 -565799

*/
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/