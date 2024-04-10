#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 5e2 + 500;
bool visited[maxn][maxn][2];
int dp[maxn][maxn][2], n;
pair <pair <int, int>, bool> par[maxn][maxn][2];
vector <int> v[maxn];
queue <pair <pair <int, int>, bool> > qu;

int main(){
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	if (a == b)
		cout << a << endl;
	else
		cout << 1 << endl;
}