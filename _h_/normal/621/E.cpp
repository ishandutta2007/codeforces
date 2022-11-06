#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef vector<vi> M;
const int inf = 2e9;
const ll md = 1e9+7;

void operator*=(M &a, const M &b){
	int sz = a.size();
	M res(sz,vi(sz));
	rep(i,0,sz) rep(j,0,sz)rep(k,0,sz)
		res[i][j] = (res[i][j]+a[i][k]*b[k][j])%md;
	a = res;
}

M xp(M a, int e){
	int sz = a.size();
	M res(sz,vi(sz));
	rep(i,0,sz) res[i][i] = 1;
	while(e){
		if(e&1)res*=a;
		a*=a;
		e/=2;
	}
	return res;
}

int main(){
	int n,b,k,x,cnt[10]={};
	cin >> n >> b >> k >> x;
	rep(_,0,n){
		int a;
		cin >> a;
		++cnt[a];
	}
	M mat(x,vi(x));
	rep(d,1,10) rep(r,0,x)
		mat[(10*r+d)%x][r] += cnt[d];
	//rep(i,0,2) {rep(j,0,2)cout<<mat[i][j]<<' ';cout<<endl;}

	mat = xp(mat, b);
	//rep(i,0,2) {rep(j,0,2)cout<<mat[i][j]<<' ';cout<<endl;}
	cout << mat[k][0] << endl;
}