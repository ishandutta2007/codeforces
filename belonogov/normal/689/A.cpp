#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;

vector < vector < int > > a = {
 {1, 2, 3},
 {4, 5, 6},
 {7, 8, 9},
 {-1, 0, -1},
};

string s;

void read() {
	int l;
	scanf("%d", &l);
	cin >> s;
}

void solve() {
	for (int dx = -3; dx <= 3; dx++)
		for (int dy = -3; dy <= 3; dy++) {
			if (dx == 0 && dy == 0) continue;;
			bool check = 1;
			for (int k = 0; k < (int)s.size(); k++) {
				int x = -1;
				int y = -1;
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 3; j++)
						if (a[i][j] == s[k] - '0') {
							x = i;
							y = j;
						}
				assert(x != -1);
				x += dx;
				y += dy;
				if (0 <= x && x < 4 && 0 <= y && y < 3 && a[x][y] != -1) {
							
				}
				else
					check = 0;
			}
			if (check) {
				puts("NO");
				return;
			}
		}
			

	puts("YES");
}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}