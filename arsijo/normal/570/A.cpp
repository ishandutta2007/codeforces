#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef int** matrix;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 101;
///#define DEBUG
#else
const ll MAX = 4001;
#endif

matrix get(istream &in, int n){
	matrix ans = new int*[n];
	for(int i = 0; i < n; i++){
		ans[i] = new int[n];
		for(int j = 0; j < n; j++)
			in >> ans[i][j];
	}
	return ans;
}

void del(matrix &m, int n){
	for(int i = 0; i < n; i++)
		delete [] m[i];
	delete [] m;
}

bool check(matrix a, matrix b, int n){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != b[i][j])
				return false;
	return true;
}

matrix multy(matrix a, matrix b, int n){
	matrix ans = new int*[n];
	for(int i = 0; i < n; i++)
		ans[i] = new int[n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			ans[i][j] = 0;
			for(int z = 0; z < n; z++)
				ans[i][j] += a[i][z] * b[z][j];
		}
	return ans;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	int a[n];
	ms(a);

	for(int i = 0; i < m; i++){
		int val = -1;
		int ind = -1;
		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			if(a > val){
				val = a;
				ind = j;
			}
		}
		a[ind]++;
	}

	int val = -1, ind = -1;
	for(int i = 0; i < n; i++)
		if(a[i] > val){
			val= a[i];
			ind = i;
		}

	cout << ind + 1;

}