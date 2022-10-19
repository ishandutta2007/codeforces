#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
//#define endl						'\n'
#define SZ(x)						ll(x.size())a

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , A[MAXN];

int ask(int x){
	if(A[x] != 0)	return A[x];
	cout << "? " << x << endl;
	cin >> A[x];
	return A[x];
}

void find(int x){
	cout << "! " << x << endl;
	exit(0);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	if(n == 1)	find(1);
	ask(1);
	ask(2);
	ask(n - 1);
	ask(n);
	if(A[1] < A[2])	find(1);
	if(A[n] < A[n - 1])	find(n);
	int l = 1 , r = n;
	while(r - l > 1){
		int mid = l + r >> 1;
		ask(mid - 1); ask(mid); ask(mid + 1);
		if(A[mid] < A[mid + 1] && A[mid] < A[mid - 1])	find(mid);
		if(A[mid] > A[mid + 1])	l = mid;
		else	r = mid;
	}

    return 0;
}
/*

*/