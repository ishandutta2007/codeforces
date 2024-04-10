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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;

int Solve(){
	cin>>n;
	if (n<=4) kill(n)
	ll lg=0;
	while ((1ll<<(2*lg))<=n) lg++;
	lg--;
	n-=(1ll<<(2*lg));
	
	int typ=n%3;
	n/=3;
	
	ans=((typ+1ll)<<(lg*2));
	for (ll tmp=1; n; n/=4, tmp*=4){
		if (!typ) ans+=tmp*(n%4);
		if (typ==1){
			if (n%4==0) ans+=0*tmp;
			if (n%4==1) ans+=2*tmp;
			if (n%4==2) ans+=3*tmp;
			if (n%4==3) ans+=1*tmp;
		}
		if (typ==2){
			if (n%4==0) ans+=0*tmp;
			if (n%4==1) ans+=3*tmp;
			if (n%4==2) ans+=1*tmp;
			if (n%4==3) ans+=2*tmp;
		}
	}
	
	kill(ans)
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
63
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63


1
29

ans : 40

*/