#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int N = 101;

ll n, k, ans;
ll A[N];
ll M[62][N][N];
ll out[N][N];

void zarb(ll a[N][N], ll b[N][N]){
	ll tmp[N][N];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			tmp[i][j]=0;
			for (int x=0; x<n; x++) tmp[i][j]=(tmp[i][j]+a[i][x]*b[x][j])%mod;
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			a[i][j]=tmp[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	k--;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			M[0][i][j]=!(__builtin_popcountll(A[i]^A[j])%3);
			//cerr<<A[i]<<' '<<A[j]<<' '<<M[0][i][j]<<endl;
		}
	}
	for (int x=1; x<62; x++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				M[x][i][j]=M[x-1][i][j];
			}
		}
		zarb(M[x], M[x]);
	}
	
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) cerr<<M[0][i][j]<<' ';cerr<<endl;
	}
	cerr<<endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) cerr<<M[1][i][j]<<' ';cerr<<endl;
	}*/
	
	
	vector<int> vec;
	for (int i=0; i<62; i++){
		if (k&(1LL<<i)) vec.push_back(i);
	}
	for (int i=0; i<n; i++){
		out[i][i]=1;
	}
	for (int i=0; i<vec.size(); i++) zarb(out, M[vec[i]]);
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			ans=(ans+out[i][j])%mod;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}