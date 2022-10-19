#include <bits/stdc++.h>
using namespace std;

int r(string &a, string &b) {
    int now = 0;
    for (int i = 0; i < 7; ++i) {
        if (a[i] == '0' && b[i] == '1') {
            ++now;
        }
        if (a[i] == '1' && b[i] == '0') return -1;
    }
    return now;
}

vector <int> ans;
vector <vector <int>> raz;
void gen(int i, int n, int k, vector <vector <bool>> &suf) {
    for (int j = 9; j >= 0; --j) {
        if (raz[i][j] == -1 || raz[i][j] > k) continue;
        if (i == n - 1) {
            if (raz[i][j] == k) {
                ans.push_back(j);
                return;
            }
        }
        else {
            if (suf[i + 1][k - raz[i][j]]) {
                ans.push_back(j);
                gen(i + 1, n, k - raz[i][j], suf);
                return;
            }
        }
    }
}

signed main() {
/*	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	int n, k;
	cin >> n >> k;
	vector <string> a(n);
	for (int i = 0; i < n; ++i) {
	    cin >> a[i];
	}
	vector <string> c(10);
	c[0] = "1110111";
	c[1] = "0010010";
	c[2] = "1011101";
	c[3] = "1011011";
	c[4] = "0111010";
	c[5] = "1101011";
	c[6] = "1101111";
	c[7] = "1010010";
	c[8] = "1111111";
	c[9] = "1111011";
	raz.resize(n, vector <int> (10));
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < 10; ++j) {
	        raz[i][j] = r(a[i], c[j]);
	    }
	}
	vector <vector <bool>> suf(n + 1, vector <bool> (k + 1));
	for (int i = n - 1; i >= 0; --i) {
	    for (int j = 0; j < 10; ++j) {
	        int tmp = raz[i][j];
	        if (tmp == -1 || tmp > k) continue;
	        if (i == n - 1) {
	            suf[i][tmp] = true;
	        }
	        else {
	            for (int j = tmp; j <= k; ++j) {
	                if (suf[i + 1][j - tmp]) {
	                    suf[i][j] = true;
	                }
	            }
	        }
	    }
	}
	gen(0, n, k, suf);
	if (!suf[0][k]) {
	    cout << -1;
	}
	else {
	    for (int j = 0; j < n; ++j) {
	        cout << ans[j];
	    }
	}
	return 0;
}