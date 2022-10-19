#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef complex<double> cd;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = (1 << 21);
const ll LOG = 21;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;
const double PI = acos(-1);

int n , m , mark[MAXN] , rev[MAXN];
cd A[MAXN];

void fft(cd *A , int inv){
	for(int i = 0 ; i < MAXN ; i++){
		if(rev[i] < i)	swap(A[i] , A[rev[i]]);
	}
	for(int len = 1 ; len < MAXN ; len *= 2){
		double ang = PI / len * (inv == 0 ? 1 : -1);
		cd wn(cos(ang) , sin(ang));
		for(int i = 0 ; i < MAXN ; i += 2 * len){
			cd w(1);
			for(int j = 0 ; j < len ; j++){
				cd x = A[i + j] , y = A[i + j + len] * w;
				A[i + j] = x + y;
				A[i + j + len] = x - y;
				w *= wn;
			}
		}
	}
	if(inv){
		for(int i = 0 ; i < MAXN ; i++)	A[i] /= MAXN;
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 1 ; i < MAXN ; i++){
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (LOG - 1));
	}
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		int x; cin >> x;
		mark[x] = 1;
		A[x] = 1;
	}
	fft(A , 0);
	for(int i = 0 ; i < MAXN ; i++)	A[i] = A[i] * A[i];
	fft(A , 1);
	vector<int> ans;
	for(int i = 0 ; i <= m ; i++){
		int val = round(A[i].real());
		if(val > 0 && mark[i] == 0)	return cout << "NO" << endl , 0;
		if(val == 0 && mark[i] == 1)	ans.push_back(i);
	}
	sort(all(ans));
	cout << "YES" << endl << SZ(ans) << endl;
	for(int i : ans)	cout << i << sep;

    return 0;
}
/*

*/