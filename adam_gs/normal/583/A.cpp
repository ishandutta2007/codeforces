#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=57;
int A[LIM], B[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n*n) {
		int a, b;
		cin >> a >> b; --a; --b;
		if(!A[a] && !B[b]) {
			cout << i+1 << " ";
			A[a]=B[b]=1;
		}
	}
	cout << '\n';
}