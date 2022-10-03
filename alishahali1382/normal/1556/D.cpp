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
#define get(a, b) (((a)>>(b))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=30;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int and12, or12;
int and13, or13;
int and23, or23;
int and1i, or1i;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	cout<<"and 1 2"<<endl; cin>>and12;
	cout<<"and 1 3"<<endl; cin>>and13;
	cout<<"and 2 3"<<endl; cin>>and23;
	cout<<"or 1 2"<<endl; cin>>or12;
	cout<<"or 1 3"<<endl; cin>>or13;
	cout<<"or 2 3"<<endl; cin>>or23;
	for (int i=0; i<30; i++){
		int x=get(and12, i)+get(and23, i)+get(and13, i);
		int y=get(or12, i)+get(or23, i)+get(or13, i);
		
		assert(x!=2 && y!=1);
		if (x==0 && y==0){
			continue ;
		}
		if (x==3 && y==3){
			A[1]|=(1<<i);
			A[2]|=(1<<i);
			A[3]|=(1<<i);
			continue ;
		}
		if (x==1 && y==3){
			if (get(and12, i)) A[1]|=(1<<i), A[2]|=(1<<i);
			if (get(and13, i)) A[1]|=(1<<i), A[3]|=(1<<i);
			if (get(and23, i)) A[2]|=(1<<i), A[3]|=(1<<i);
			continue ;
		}
		if (x==0 && y==2){
			if (!get(or12, i)) A[3]|=(1<<i);
			if (!get(or13, i)) A[2]|=(1<<i);
			if (!get(or23, i)) A[1]|=(1<<i);
			continue ;
		}
		assert(0);
	}
	for (int i=4; i<=n; i++){
		cout<<"and 1 "<<i<<endl; cin>>and1i;
		cout<<"or 1 "<<i<<endl; cin>>or1i;
		for (int j=0; j<30; j++){
			if (get(A[1], j)) A[i]|=(get(and1i, j)<<j);
			else A[i]|=(get(or1i, j)<<j);
		}
	}
//	cerr<<"A: ";for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	sort(A+1, A+n+1);
	cout<<"finish "<<A[k]<<endl;
	
	return 0;
}
/*
5 3
1 0 1 1 0
0
1
0
1
1
1


*/