#include<bits/stdc++.h>

using namespace std;

const int MX = 100000;

int u[MX], v[MX];
vector< pair<int, pair<int, int> > > e;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		e.push_back(make_pair(a, make_pair(-b, i)));
	}
	
	sort(e.begin(), e.end());
	
	int U = 0, V = 2, k = 0;
	for (auto E : e) {
		if (E.second.first == -1) {
			u[E.second.second] = k;
			v[E.second.second] = k + 1;
			
			k++;
		}
		else {
			if (V > k) {
				printf("-1\n");
				
				return 0;
			}
			
			u[E.second.second] = U;
			v[E.second.second] = V;
			
			if (U == V - 2) {
				V++;
				U = 0;
			}
			else {
				U++;
			}
		}
	}
	
	for (int i = 0; i < m; i++) printf("%d %d\n", u[i] + 1, v[i] + 1);
	
	return 0;
}