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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];
string S;

void calcA(){
	for (int i=1; i<=2*n; i++){
		if (S[i-1]=='(') A[i]=+1;
		else A[i]=-1;
	}
}
void calcB(){
	for (int i=1; i<=2*n; i++) B[i]=B[i-1]+A[i];
}
bool check(){
	for (int i=1; i<=2*n; i++) if (B[i]<0) return 0;
	return 1;
}

int Main(){
	cin>>n>>S;
	calcA();
	calcB();
	if (check()) kill(0)
	int l=-1, r=-1;
	for (int i=1; i<=2*n; i++){
		if (B[i]<0){
			if (l==-1) l=i;
			r=i;
		}
	}
	l=max_element(B, B+l+1)-B+1;
	r=max_element(B+r, B+2*n+1)-B;
//	debug2(l, r)
	reverse(A+l, A+r+1);
	calcB();
	if (check()){
		cout<<"1\n";
		cout<<l<<" "<<r<<"\n";
		return 0;
	}
	
	calcA();
	calcB();
	int pos=max_element(B, B+2*n+1)-B;
	cout<<"2\n";
	cout<<1<<" "<<pos<<"\n";
	cout<<pos+1<<" "<<2*n<<"\n";
	
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
2
(())

1
5
())((()))(

1
6
())((()))(()


*/