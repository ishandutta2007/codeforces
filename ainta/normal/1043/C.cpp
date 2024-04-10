#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
char p[1010];
string A = "", B = "";
int Path[1010][2], res[1010];
int main() {
	int i, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		string tB = B;
		string tA = A;
		reverse(tA.begin(), tA.end());
		reverse(tB.begin(), tB.end());
		string q1 = A + p[i], q2 = p[i] + tB;
		string r1 = B + p[i], r2 = p[i] + tA;
		string tr1 = r1, tr2 = r2;
		reverse(tr1.begin(), tr1.end());
		reverse(tr2.begin(), tr2.end());
		if (q1 < q2) {
			A = q1;
			Path[i + 1][0] = 1;
		}
		else {
			A = q2;
			Path[i + 1][0] = 2;
		}
		if (tr1 < tr2) {
			B = r1;
			Path[i + 1][1] = 1;
		}
		else {
			B = r2;
			Path[i + 1][1] = 2;
		}
	}
	int n = i;
	int x = n, y = 0;
	while (x) {
		if (y == 0) {
			if (Path[x][y] == 1) {
				res[x] = 0;
				x--;
			}
			else {
				res[x] = 1;
				x--, y = 1;
			}
		}
		else {
			if (Path[x][y] == 1) {
				res[x] = 0;
				x--;
			}
			else {
				res[x] = 1;
				x--, y = 0;
			}
		}
	}
	for (i = 1; i <= n; i++)printf("%d ", res[i]);
}