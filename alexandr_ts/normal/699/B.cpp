#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e3;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int a[N][N];
int b[N], c[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
	int n, m, cnt = 0;
	set <int> s1, s2;
	cin >> n >> m;

	fr(i, n)
        fr(j, m) {
            char c1;
            cin >> c1;
            if (c1 == '*') {
                a[i][j] = 1;
                b[i]++, c[j]++, cnt++;
            }
        }
    fr(i, n)
        fr(j, m)
            if (b[i] + c[j] - a[i][j] == cnt) {
                cout << "YES" << endl << i + 1 << " " << j + 1;
                return 0;
            }
    cout << "NO";





}