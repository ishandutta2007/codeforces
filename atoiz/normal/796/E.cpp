#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int getint()
{
    bool neg = 0;
    int n = 0;
    char ch = getchar();
    if (ch == '-') {
        neg = 1;
        ch = getchar();
    }
    while (ch > 47 && ch < 58) {
        n = n * 10 + ch - 48;
		ch = getchar();
    }
    return (neg ? -n : n);
}

int n, p, k;
vector<bool> va, vb;
vector< vector<int> > ga, gb;

void init()
{
    ga.assign(n, vector<int>(k+1));

    for (int pos = 0; pos < n; ++pos) {
		for (int j = 0; j < k; ++j) {
			int cnt = 0;
            for (int i = pos; i < pos + k && i < n; ++i) {
                if (va[i] && not(i < pos + j && vb[i])) ++cnt;
            }
			ga[pos][j] = cnt;
		}
    }

    gb.assign(n, vector<int>(k+1));

    for (int pos = 0; pos < n; ++pos) {
		for (int j = 0; j < k; ++j) {
			int cnt = 0;
            for (int i = pos; i < pos + k && i < n; ++i) {
                if (vb[i] && not(i < pos + j && va[i])) ++cnt;
            }
			gb[pos][j] = cnt;
		}
    }
}

int main()
{
	n = getint(), p = getint(), k = getint();
	++n;

    int sza, szb, v;
    va.assign(n+1, 0);
    vb.assign(n+1, 0);

    sza = getint();
	for (int i = 0; i < sza; ++i) {
		v = getint();
        va[v] = 1;
	}

    szb = getint();
	for (int i = 0; i < szb; ++i) {
		v = getint();
        vb[v] = 1;
	}
	init();
//	cerr << ga[5][4] << endl;

    if (p >= ((n-1)/k+1)*2) {
        int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (va[i] || vb[i]) ++cnt;
		}
		cout << cnt << endl;
		return 0;
    }

    int dp[2][p+3][k+1][k+1];

    for (int glance = 0; glance <= p; ++glance) {
		for (int i = 0; i <= k; ++i) {
			for (int j = 0; j <= k; ++j) {
				dp[1][glance][i][j] = INT_MIN;
			}
		}
	}
	dp[1][0][0][0] = 0;

    for (int pos = 1; pos < n; ++pos) {
        for (int glance = 0; glance <= p; ++glance) {
			for (int i = 0; i <= k; ++i) {
				for (int j = 0; j <= k; ++j) {
//					cerr << "dp[" << pos << "][" << glance << "][" << i << "][" << j << "] = " << dp[pos&1][glance][i][j] << endl;
					dp[(pos&1)^1][glance][i][j] = INT_MIN;
				}
			}
        }

        for (int g = 0; g <= p; ++g) {
			// i = 0, j = 0
            dp[ (pos&1)^1 ][g  ][0  ][0  ] = max(dp[ (pos&1)^1 ][g  ][0  ][0  ], dp[pos&1][g][0][0]);
            dp[ (pos&1)^1 ][g+1][0  ][k-1] = max(dp[ (pos&1)^1 ][g+1][0  ][k-1], dp[pos&1][g][0][0] + gb[pos][0]);
            dp[ (pos&1)^1 ][g+1][k-1][0  ] = max(dp[ (pos&1)^1 ][g+1][k-1][0  ], dp[pos&1][g][0][0] + ga[pos][0]);
            dp[ (pos&1)^1 ][g+2][k-1][k-1] = max(dp[ (pos&1)^1 ][g+2][k-1][k-1], dp[pos&1][g][0][0] + ga[pos][0] + gb[pos][k]);


			// i = 0, j > 0
			for (int j = 1; j <= k; ++j) {
				dp[ (pos&1)^1 ][g][0][j-1] = max(dp[ (pos&1)^1 ][g][0][j-1],
												 dp[pos&1][g][0][j]);
				dp[ (pos&1)^1 ][g+1][k-1][j-1] = max(dp[ (pos&1)^1 ][g+1][k-1][j-1],
										 		     dp[pos&1][g][0][j] + ga[pos][j]);
			}
			// i > 0, j = 0
			for (int i = 1; i <= k; ++i) {
				dp[ (pos&1)^1 ][g][i-1][0] = max(dp[ (pos&1)^1 ][g][i-1][0],
												 dp[pos&1][g][i][0]);
				dp[ (pos&1)^1 ][g+1][i-1][k-1] = max(dp[ (pos&1)^1 ][g+1][i-1][k-1],
										 		     dp[pos&1][g][i][0] + gb[pos][i]);
			}
			// i > 0, j > 0
			for (int i = 1; i <= k; ++i) {
				for (int j = 1; j <= k; ++j) {
                    dp[ (pos&1)^1 ][g][i-1][j-1] = max(dp[ (pos&1)^1 ][g][i-1][j-1],
													   dp[pos&1][g][i][j]);
				}
			}
        }
    }

    int ans = INT_MIN;
    for (int glance = 0; glance <= p; ++glance) {
        for (int i = 0; i <= k; ++i) {
        	for (int j = 0; j <= k; ++j) {
                ans = max(ans, dp[n&1][glance][i][j]);
        	}
        }
    }
    cout << ans << endl;
}