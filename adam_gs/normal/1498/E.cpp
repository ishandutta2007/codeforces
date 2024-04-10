#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=507;
int T[LIM];
int main() {
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	for(int wynik=n; wynik>=0; --wynik) {
		rep(i, n) rep(j, i) if(abs(T[i]-T[j])==wynik) {
			if(T[i]>=T[j]) {
				cout << "? " << i+1 << " " << j+1 << endl;
			} else {
				cout << "? " << j+1 << " " << i+1 << endl;
			}
			string x;
			cin >> x;
			if(x=="Yes") {
				cout << "! " << i+1 << " " << j+1 << endl;
				return 0;
			}
		}
	}
	cout << "! 0 0" << endl;
}