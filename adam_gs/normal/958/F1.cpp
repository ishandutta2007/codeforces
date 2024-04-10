#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=107;
int T[LIM], ile[LIM], akt[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		cin >> T[i]; --T[i];
	}
	int sum=0;
	rep(i, m) {
		cin >> ile[i];
		sum+=ile[i];
	}
	rep(i, n-sum+1) {
		rep(j, m) akt[j]=0;
		rep(j, sum) ++akt[T[i+j]];
		bool ok=true;
		rep(j, m) if(akt[j]!=ile[j]) ok=false;
		if(ok) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}