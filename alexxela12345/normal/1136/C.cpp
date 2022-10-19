#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf("%d", &a[i][j]);
	}
    }
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf("%d", &b[i][j]);
	}
    }

    vector<vector<int>> a1(n + m), b1(n + m);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    int rr = i + j;
	    a1[rr].push_back(a[i][j]);
	    b1[rr].push_back(b[i][j]);
	}
    }
    for (int i = 0; i < n + m; i++) {
	sort(a1[i].begin(), a1[i].end());
	sort(b1[i].begin(), b1[i].end());
    }
    if (a1 == b1) {
	printf("YES\n");
    } else {
	printf("NO\n");
    }

    return 0;
}