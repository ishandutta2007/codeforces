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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b, c, d, ans;
int A[MAXN];
string S;

int Main(){
	cin>>a>>b>>c>>d>>S;
	int cA=0, cB=0;
	for (char c:S){
		if (c=='A') cA++;
		else cB++;
	}
	if (cA!=a+c+d || cB!=b+c+d) kill("NO")
	
	vector<int> v1, v2;
	
	S+=S.back();
	int l=0, odd=0, sum1=0, sum2=0;
	for (int r=1; r<SZ(S); r++) if (S[r]==S[r-1]){
		int len=r-l, k=len/2;
		if (len%2==1) odd+=k;
		else{
			if (S[l]=='A') v1.pb(k), sum1+=k;
			else v2.pb(k), sum2+=k;
		}
		l=r;
	}
	
//	debugv(v1)
//	debugv(v2)
	
	sort(all(v1));
	sort(all(v2));
	for (int x:v1){
		if (c>=x) c-=x;
		else{
			d-=x-1-c;
			c=0;
		}
	}
	for (int x:v2){
		if (d>=x) d-=x;
		else{
			c-=x-1-d;
			d=0;
		}
	}
	if (c+d>odd) kill("NO")
	kill("YES")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
2 3 5 4
AABAABBABAAABABBABBBABB

*/