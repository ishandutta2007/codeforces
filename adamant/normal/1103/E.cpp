#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int mod = 1LL << 58;

int c10[5] = {1, -1, 1, -1, 1};

const int maxn = 100000;

int A[maxn][10];



void print(int *A) {
	for(int i = 0; i < 10; i++) {
		cout << A[i] << ' ';
	}
	cout << endl;
}

template<typename T>
void transform(T *from, T *to, bool inv = false) {
	if(to - from == 1) {
		return;
	} else {
		int N = to - from, n = N / 10;
		for(int i = 0; i < 10; i++) {
			transform(from + i * n, from + (i + 1) * n, inv);
		}
		for(int i = 0; i < n; i++) {
			int X[10][10];
			for(int j = 0; j < 10; j++) {
				for(int k = 0; k < 10; k++) {
					X[j][k] = from[i + j * n][k];
				}
			}
			
			int Y[10][10];
			memset(Y, 0, 100 * sizeof(int));
			// Y[k] = sum X[j] * w[j * k]
			
			for(int k = 0; k < 10; k++) {
				int t = 0; // t = j * k % 10
				for(int j = 0; j < 10; j++) {
					int nz = t; // nz = z + t
					for(int z = 0; z < 10; z++) {
						if(nz >= 10) {
							nz -= 10;
						}
						Y[k][nz] += X[j][z];
						nz++;
					}
					t += k;
					if(t >= 10) {
						t -= 10;
					}
				}
			}
			
			for(int j = 0; j < 10; j++) {
				for(int k = 0; k < 10; k++) {
					from[i + j * n][k] = Y[inv ? (10 - j) % 10 : j][k];
				}
			}
		}
	}
}

void mul(int *A, int *B, int *C) {
	int res[10];
	memset(res, 0, 10 * sizeof(int));
	for(int i = 0; i < 10; i++) {
		int ij = i;
		for(int j = 0; j < 10; j++) {
			res[ij] += A[i] * B[j];
			ij += 1;
			if(ij >= 10) {
				ij -= 10;
			}
		}
	}
	memcpy(C, res, 10 * sizeof(int));
}

void bpow(int *A, int n) {
	int PW[10];
	memset(PW, 0, 10 * sizeof(int));
	PW[0] = 1;
	for(int i = 0; i < 30; i++) {
		if((n >> i) & 1) {
			mul(A, PW, PW);
		}
		mul(A, A, A);
	}
	memcpy(A, PW, 10 * sizeof(int));
}

void simplify(int *A) {
	for(int j = 9; j >= 4; j--) {
		for(int k = 0; k < 4; k++) {
			A[j - 4 + k] -= c10[k] * A[j];
		}
		A[j] = 0;
	}
}

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		A[x][0]++;
	}
	transform(A, A + maxn);
	for(int i = 0; i < maxn; i++) {
		bpow(A[i], n);
	}
	int inv5 = bpow(bpow(5, mod / 2 - 1), 5);
	int div2 = 2 * 2 * 2 * 2 * 2;
	transform(A, A + maxn, 1);
	for(int i = 0; i < n; i++) {
		simplify(A[i]);
		A[i][0] /= div2;
		cout << (uint64_t(A[i][0] * inv5) & (mod - 1)) << "\n";
	}
    return 0;
}