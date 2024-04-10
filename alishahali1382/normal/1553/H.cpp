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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=(1<<19), K=19;

int n, m, k, u, v, x, y, t, a, b;
int A[N];
int ans[K+1][N];
int Mn[K+1][N], Mx[K+1][N];

void Solve(int tl, int tr, int bit){
	int pos=((A[tl]>>bit)<<bit);
	if (bit==0){
		ans[bit][pos]=inf;
		Mn[bit][pos]=Mx[bit][pos]=A[tl];
		return ;
	}
	int mid=tr;
	for (int i=tl; i<tr; i++) if (getbit(A[i], bit-1)){
		mid=i;
		break ;
	}
	int tav=(1<<(bit-1));
	if (mid==tl || mid==tr){
		Solve(tl, tr, bit-1);
		int tmp=(A[tl]&(1<<(bit-1)));
		int pos2=(pos^tmp);
		for (int i=0; i<tav; i++){
			Mn[bit][pos+i]=Mn[bit-1][pos+tmp+i];
			Mx[bit][pos+i]=Mx[bit-1][pos+tmp+i];
			Mn[bit][pos+tav+i]=Mn[bit-1][pos+tmp+i]^tav;
			Mx[bit][pos+tav+i]=Mx[bit-1][pos+tmp+i]^tav;
			ans[bit][pos+i]=ans[bit][pos+i+tav]=ans[bit-1][pos+tmp+i];
		}
		return ;
	}
	Solve(tl, mid, bit-1);
	Solve(mid, tr, bit-1);
	for (int i=0; i<tav; i++){
		Mn[bit][pos+i]=min(Mn[bit-1][pos+i], Mn[bit-1][pos+tav+i]);
		Mx[bit][pos+i]=max(Mx[bit-1][pos+i], Mx[bit-1][pos+tav+i]);
		
		Mn[bit][pos+tav+i]=min(Mn[bit-1][pos+i]^tav, Mn[bit-1][pos+tav+i]^tav);
		Mx[bit][pos+tav+i]=max(Mx[bit-1][pos+i]^tav, Mx[bit-1][pos+tav+i]^tav);
		
		ans[bit][pos+i]=min({ans[bit-1][pos+i], ans[bit-1][pos+tav+i], Mn[bit-1][pos+tav+i]-Mx[bit-1][pos+i]});
		ans[bit][pos+tav+i]=min({ans[bit-1][pos+i], ans[bit-1][pos+tav+i], (Mn[bit-1][pos+i]^tav)-(Mx[bit-1][pos+tav+i]^tav)});
		/*
		if ((Mn[bit-1][pos+i]^tav)<(Mx[bit-1][pos+tav+i]^tav)){
			debug2(bit, i)
			debug2(pos, tav)
			debug(Mn[bit-1][pos+i])
			debug(Mx[bit-1][pos+tav+i])
			cerr<<"\n\n";
			
		}*/
		
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=0; i<n; i++) cin>>A[i];
	sort(A, A+n);
	Solve(0, n, k);
	for (int i=0; i<(1<<k); i++) cout<<ans[k][i]<<" \n"[i==(1<<k)-1];
	
//	cerr<<"Mn[0]: ";for (int i=0; i<8; i++) cerr<<Mn[0][i]<<" \n"[i==7];
//	cerr<<"Mn[1]: ";for (int i=0; i<8; i++) cerr<<Mn[1][i]<<" \n"[i==7];
//	cerr<<"Mn[2]: ";for (int i=0; i<8; i++) cerr<<Mn[2][i]<<" \n"[i==7];
//	cerr<<"Mn[3]: ";for (int i=0; i<8; i++) cerr<<Mn[3][i]<<" \n"[i==7];
	
	return 0;
}