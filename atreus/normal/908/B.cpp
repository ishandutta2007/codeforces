#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e3 + 100;
int a[maxn];
string s[maxn];
int v[10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int homx, homy, desx, desy;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++){
			if (s[i][j] == 'S'){
				homx = i;
				homy = j;
			}
			if (s[i][j] == 'E'){
				desx = i;
				desy = j;
			}
		}
	}
	string a;
	cin >> a;
	for (int i = 0; i < 4; i++)
		v[i] = i;
	int cnt = 0;
	do {
		int q = homx;
		int p = homy;
//		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
//		cout << q << " " << p << endl;
		for (int i = 0; i < a.size(); i++){
			if (a[i] - '0' == v[0])
				p ++;
			if (a[i] - '0' == v[1])
				q --;
			if (a[i] - '0' == v[2])
				p --;
			if (a[i] - '0' == v[3])
				q ++;
//			cout << a[i] << " -> " << q << " " << p << endl;
			if (p < 0 || q < 0 || q >= n || p >= m || s[q][p] == '#')
				break;
			if (s[q][p] == 'E'){
				cnt ++;
				break;
			}
		}
	} while (next_permutation (v, v + 4));
	cout << cnt << endl;
}