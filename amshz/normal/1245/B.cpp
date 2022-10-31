#include <bits/stdc++.h>
using namespace std;
typedef long long           ll;
typedef long double         ld;
#define F                   first
#define S                   second

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	int qq;
	cin >> qq;
	while (qq--){
		int n;
		cin >> n;
		int a, b, c, x, y, z;
		string g;
		cin >> a >> b >> c;
		cin >> g;
		x = 0, y = 0, z = 0;
		for (int i=0; i<n; i++){
			if (g[i] == 'R') x++;
			else if (g[i] == 'P') y++;
			else z++;
		}
		int win = (n+1)/2;
		if (min(b, x) + min(z, a) + min(c, y) >= win){
			cout << "YES" << endl;
			int t1 = a, t2 = b, t3 = c;
			char ans[110];
			bool f[110];
			for (int i=0; i<n; i++) f[i] = false;
			int p = min(b, x);
			for (int i=0; i<n; i++){
				if (p == 0) break;
				if (g[i] == 'R') p--, t2--, f[i] = true, ans[i] = 'P';
			}
			p = min(c, y);
			for (int i=0; i<n; i++){
				if (p == 0) break;
				if (g[i] == 'P') p--, t3--, f[i] = true, ans[i] = 'S';
			}
			p = min(a, z);
			for (int i=0; i<n; i++){
				if (p == 0) break;
				if (g[i] == 'S') p--, t1--, f[i] = true, ans[i] = 'R';
			}
			for (int i=0; i<n; i++){
				if (f[i]) continue;
				if (t1 > 0) ans[i] = 'R', t1--;
				else if (t2 > 0) ans[i] = 'P', t2--;
				else ans[i] = 'S', t3--;
			}
			for (int i=0; i<n; i++) cout << ans[i];
			cout << endl;
		}
		else cout << "NO" << endl;
	}
}