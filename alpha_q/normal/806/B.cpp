#include <bits/stdc++.h> 

using namespace std;

const int MAGIC = 5000;
const int INF = 2e9 + 10;

long double l[] = {0.0, 1.0/2.0, 1.0/4.0, 1.0/8.0, 1.0/16.0, 1.0/32.0, -1.0};
long double r[] = {0.0, 1.0, 1.0/2.0, 1.0/4.0, 1.0/8.0, 1.0/16.0, 1.0/32.0};
int n, ans = INF, a[150][7], sol[7], ptr;

void go (vector <int> x) {
	int vas = 0, pet = 0;
	for (int i = 0; i < 5; ++i) {
		if (a[1][i] != -1) vas += x[i] * 2 * (250 - a[1][i]);
		if (a[2][i] != -1) pet += x[i] * 2 * (250 - a[2][i]);
	}
	// cout << vas << " " << pet << endl;
	if (vas > pet) {
		for (int i = 0; i < MAGIC; ++i) {
			int works = 1;
			for (int j = 0; j < 5; ++j) {
				int cur = x[j];
				if (a[1][j] == -1) {
					long double lt = (n + i) * 1.0 * l[cur];
					long double rt = (n + i) * 1.0 * r[cur];
					// if (i == 2) cout << lt << " " << rt << " " << sol[j] << endl;
					if (!(lt < sol[j] and sol[j] <= rt)) {
						works = 0;
						break;
					}	
					continue;
				}
				long double lt = (n + i) * 1.0 * l[cur] - sol[j];
				long double rt = (n + i) * 1.0 * r[cur] - sol[j];
				// if (i == 2) cout << lt << " " << rt << endl;
				rt = min(rt, (long double) i);
				if (lt >= rt or floor(rt) <= lt or floor(rt) < 0.0) {
					works = 0;
					break;
				} 
			}
			if (works) {
				// if (i == 1) cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << " " << x[4] << endl;
				ans = min(ans, i);
				break;
			}
		}
	}
}

int main (int argc, char const *argv[]) {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
  	for (int j = 0; j < 5; ++j) {
  		scanf("%d", a[i] + j);
  		if (a[i][j] != -1) {
  			++sol[j];
  		} 
  	}
  }
  vector <int> v(5);
  // v[0] = v[1] = v[2] = 1, v[3] = 3, v[4] = 6;
  // go(v);
  for (v[0] = 1; v[0] <= 6; ++v[0]) {
  	for (v[1] = 1; v[1] <= 6; ++v[1]) {
  		for (v[2] = 1; v[2] <= 6; ++v[2]) {
  			for (v[3] = 1; v[3] <= 6; ++v[3]) {
  				for (v[4] = 1; v[4] <= 6; ++v[4]) {
  					go(v);
  				}
  			}
  		}
  	}
  }
  if (ans >= INF/2) ans = -1;
  cout << ans << endl;
  return 0;
}