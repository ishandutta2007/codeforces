#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 998244353
#define N 300005
#define INF 101111111111111
using namespace std;
int main(){
	FAST
	cout << "? ";
	for(ull i = 1;i<=100;i++) cout << (i<<7) << " ";
	cout << endl;
	ull xor1;
	cin >> xor1;
    cout << "? ";
    for(ull i = 1;i<=100;i++) cout << i << " ";
    cout << endl;
    ull xor2;
    cin >> xor2;
    xor1 = xor1 & 127;
    xor2 = xor2 & ~127;
    ll res = xor1|xor2;
    cout << "! " << res << endl;
}