# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 2e3+10;
ll a[xn][3];
bool f[xn];

ll dis(ll q1, ll w1, ll e1, ll q2, ll w2, ll e2){
	ll q = abs(q1-q2);
	ll w = abs(w1-w2);
	ll e = abs(e1-e2);
	return (pow(q,2)+pow(w,2)+pow(e,2));
}

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++) cin >> a[i][j];
	int t = 0;
	for (int i=0; i<n; i++){
		ll mn = 1e18;
		int dx = -1;
		if (t == n) break;
		if (f[i]) continue;
		for (int j=0; j<n; j++){
			if (f[j] or i == j) continue;
			if (t == n) break;
			ll d = dis(a[i][0], a[i][1], a[i][2], a[j][0], a[j][1], a[j][2]);
			if (d < mn){
				mn = d;
				dx = j;
			}
		}
		cout << i+1 << ' ' << dx+1 << endl;
		f[i] = true, f[dx] = true;
		t += 2;
	}
}