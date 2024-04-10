# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 11;
const int INF = 10000000051;
struct Node{
	int nm1, nm2;
	bool operator < (const Node &o) const{
		if (nm1 != o.nm1) return nm1 < o.nm1;
		else return nm2 < o.nm2;
	}
	Node operator + (const Node &o) const{
		return (Node){nm1 + o.nm1, nm2 + o.nm2};
	}
};
int n;
Node f[NR][NR][3][NR][NR][3];
Node dp[NR * NR][3];
int px[NR * NR], py[NR * NR];
int main(){
	scanf("%d", &n);
	for (int x1 = 0; x1 < n; x1++){
		for (int y1 = 0; y1 < n; y1++){
			for (int p1 = 0; p1 < 3; p1++){
				for (int x2 = 0; x2 < n; x2++){
					for (int y2 = 0; y2 < n; y2++){
						for (int p2 = 0; p2 < 3; p2++){
							f[x1][y1][p1][x2][y2][p2] = (Node){1000000000, 1000000000};
						}
					}
				}
			}
		}
	}
	int m0[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
	for (int x1 = 0; x1 < n; x1++){
		for (int y1 = 0; y1 < n; y1++){
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 8; k++){
					int x2 = x1 + m0[k][0], y2 = y1 + m0[k][1];
					// if (x1 == 0 && y1 == 0 && x2 == 2 && y2 == 1) printf("------------- %d\n", j);
					if (x2 >= n || x2 < 0 || y2 >= n || y2 < 0) continue;
					f[x1][y1][j][x2][y2][0] = (Node){1 + (j != 0), j != 0};
				}
				for (int k = 1; ; k++){
					int x2 = x1 - k, y2 = y1 - k;
					if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) break;
					f[x1][y1][j][x2][y2][1] = (Node){1 + (j != 1), j != 1};
				}
				for (int k = 1; ; k++){
					int x2 = x1 + k, y2 = y1 + k;
					if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) break;
					f[x1][y1][j][x2][y2][1] = (Node){1 + (j != 1), j != 1};
				}
				for (int k = 1; ; k++){
					int x2 = x1 + k, y2 = y1 - k;
					if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) break;
					f[x1][y1][j][x2][y2][1] = (Node){1 + (j != 1), j != 1};
				}
				for (int k = 1; ; k++){
					int x2 = x1 - k, y2 = y1 + k;
					if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) break;
					f[x1][y1][j][x2][y2][1] = (Node){1 + (j != 1), j != 1};
				}
				for (int k = 0; k < n; k++){
					if (k != y1) f[x1][y1][j][x1][k][2] = (Node){1 + (j != 2), j != 2};
					if (k != x1) f[x1][y1][j][k][y1][2] = (Node){1 + (j != 2), j != 2};
				}
			}
		}
	}
	for (int x3 = 0; x3 < n; x3++){
		for (int y3 = 0; y3 < n; y3++){
			for (int p3 = 0; p3 < 3; p3++){
				for (int x1 = 0; x1 < n; x1++){
					for (int y1 = 0; y1 < n; y1++){
						for (int p1 = 0; p1 < 3; p1++){
							for (int x2 = 0; x2 < n; x2++){
								for (int y2 = 0; y2 < n; y2++){
									for (int p2 = 0; p2 < 3; p2++){
										f[x1][y1][p1][x2][y2][p2] = min(f[x1][y1][p1][x2][y2][p2], f[x1][y1][p1][x3][y3][p3] + f[x3][y3][p3][x2][y2][p2]);
										if (x3 == 2 && y3 == 1 && x1 == 0 && y1 == 2 && x2 == 2 && y2 == 0 && p1 == 0 && p3 == 0 && p2 == 2){
											// printf("---------------- %d %d\n", f[x1][y1][p1][x2][y2][p2].nm1, f[x1][y1][p1][x2][y2][p2].nm2);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int a;
			scanf("%d", &a);
			px[a] = i;
			py[a] = j;
		}
	}
	dp[1][0] = dp[1][1] = dp[1][2] = (Node){0, 0};
	for (int i = 2; i <= n * n; i++){
		for (int j = 0; j < 3; j++){
			dp[i][j] = (Node){1000000000, 1000000000};
			dp[i][j] = min(dp[i][j], dp[i - 1][0] + f[px[i - 1]][py[i - 1]][0][px[i]][py[i]][j]);
			dp[i][j] = min(dp[i][j], dp[i - 1][1] + f[px[i - 1]][py[i - 1]][1][px[i]][py[i]][j]);
			dp[i][j] = min(dp[i][j], dp[i - 1][2] + f[px[i - 1]][py[i - 1]][2][px[i]][py[i]][j]);
			// printf("dp %d %d %d %d\n", i, j, dp[i][j].nm1, dp[i][j].nm2);
		}
	}
	Node ans = min(dp[n * n][0], min(dp[n * n][1], dp[n * n][2]));
	printf("%d %d\n", ans.nm1, ans.nm2);
	return 0;
}