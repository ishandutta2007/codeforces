#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

char c[200][200];
bool b[200][200];
char ans[200][200];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int f = 0; f < n; f++) {
			c[i][f] = getchar();
		}
	}
	ans[n - 1][n - 1] = 'o';
	for(int i = -50; i <= 50; i++) {
		for(int f = -50; f <= 50; f++) {
			bool ok = 1, ok2 = 0;
			{
				for(int px = 0; px < n; px++) {
					for(int py = 0; py < n; py++) {
						if(px + i < 0 || px + i >= n || py + f < 0 || py + f >= n || c[px][py] != 'o') {
							continue;
						}
						if(!(c[px + i][py + f] == 'x' || c[px + i][py + f] == 'o')) {
//							if(i == 1 && f == 0) {
//								cout << px << " " << py << endl;
//							}
							ok = 0;
						} else {
							if(c[px + i][py + f] == 'x') {
								ok2 = 1;
							}
						}
					}
				}
			}
			if(ok && ok2) {
				ans[n - 1 + i][n - 1 + f] = 'x';
				for(int px = 0; px < n; px++) {
					for(int py = 0; py < n; py++) {
						if(px + i < 0 || px + i >= n || py + f < 0 || py + f >= n || c[px][py] != 'o') {
							continue;
						}
						if(c[px + i][py + f] == 'x' || c[px + i][py + f] == 'o') {
							b[px + i][py + f] = 1;
						}
					}
				}
			}
		}
	}

	bool ok = 1;

	for(int i = 0; i < n; i++) {
		for(int f = 0; f < n; f++) {
			if(c[i][f] == 'x' && b[i][f] == 0) {
				ok = 0;
			}
		}
	}

	if(!ok) {
		printf("NO");
		return(0);
	}

	printf("YES\n");

	for(int i = 0; i < 2 * n - 1; i++) {
		for(int f = 0; f < 2 * n - 1; f++) {
			if(ans[i][f] == 'o' || ans[i][f] == 'x') {
				printf("%c", ans[i][f]);
			} else {
				printf(".");
			}
		}
		printf("\n");
	}

	return(0);
}

// by Kim Andrey