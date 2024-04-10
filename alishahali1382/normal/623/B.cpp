#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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
const int MAXN = 1000100, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans=INF;
int A[MAXN];
int bad[MAXN];
vector<int> D;

void add(int x){
	for (int i=2; i<=x; i++) if (x%i==0){
		D.pb(i);
		while (x%i==0) x/=i;
	}
	if (x>1) D.pb(x);
}

ll calc(int d){
	int mn=0, mx=0, t=0;
	for (int i=1; i<=n; i++){
		int tmp=A[i]%d;
		if (tmp==1 || tmp==d-1){
			bad[i]=1;
			t++;
			continue ;
		}
		bad[i]=0;
		if (!tmp) continue ;
		if (!mn) mn=i;
		mx=i;
	}
	if (!mx){
		ll res=0, sum=0;
		for (int i=1; i<=n; i++) res=max(res, sum=max(0ll, sum+bad[i]*b-a));
		return b*t-res;
	}
	for (int i=1; i<=n; i++) bad[i]+=bad[i-1];
	
	ll res1=INF, res2=INF;
	for (int i=mx; i<=n; i++) res1=min(res1, (i-mn+1)*a+(bad[n]-bad[i])*b);
	for (int i=0; i<mn; i++) res2=min(res2, (mn-i-1)*a+bad[i]*b);
	
	return res1+res2;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>a>>b;
	for (int i=1; i<=n; i++) cin>>A[i];
	add(A[1]-1);
	add(A[1]);
	add(A[1]+1);
	if (D.size()<3){
		add(A[n]-1);
		add(A[n]);
		add(A[n]+1);
	}
	
	sort(all(D));
	D.resize(unique(all(D))-D.begin());  // D.size() <= 24
	
	for (int d:D) ans=min(ans, calc(d));
	
	cout<<ans<<'\n';
	
	return 0;
}
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