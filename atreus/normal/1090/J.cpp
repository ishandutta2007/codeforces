#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int z[maxn], f[maxn], g[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int lz = 0, rz = 0;
	for (int i = 1; i < m; i++){
		if (rz < i){
			lz = rz = i;
			while (rz < m and t[rz - lz] == t[rz])
				rz ++;
			z[i] = rz - lz;
			rz --;
		}
		else{
			int k = i - lz;
			if (z[k] < rz - i + 1)
				z[i] = z[k];
			else{
				lz = i;
				while (rz < m and t[rz - lz] == t[rz])
					rz ++;
				z[i] = rz - lz;
				rz --;
			}
		}
	}
	f[0] = f[1] = 0;
	int k = 0;
	for (int i = 1; i < m; i++){
		while (k > 0 and t[i] != t[k])
			k = f[k];
		k += (t[i] == t[k]);
		f[i + 1] = k;
	}
	for (int i = 1; i < m; i++)
		g[i] = max(z[i], g[f[i]]);
	
	ll answer = m;
	k = 0;
	for (int i = 1; i < n; i++){
		while (k > 0 and s[i] != t[k])
			k = f[k];
		k += (s[i] == t[k]);
		if (k == m)
			k = f[k];
		answer += m - g[k];
	}
	cout << answer << endl;
}