#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
	int n,k;
	cin >> n >> k;
	set <int> s1;
	fop (i,1,k+2) s1.insert(i);
	int aa = 0, bb = 0, now_aa = 0; // aa is bigger
	fop (i,1,k+2) {
		cout << "? ";
		for (int j : s1) {
			if (j != i) cout << j << ' ';
		}
		cout << endl;
		int a,b;
		cin >> a >> b;
		cout.flush();
		if (now_aa < b) {
			swap(aa, bb);
			now_aa = b;
		}
		if (b == now_aa) aa++;
		else bb++;
	}
	cout << "! " << aa << endl;
	return 0;
}