#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#define S second
#define F first
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 100;
int n, m, k, w, dp[maxn], par[maxn];
vector <pair <int, int> > v[maxn], ans;
set <pair <int, int> > s;
string a[maxn][maxn];
bool visited[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	string s;
	cin >> n >> s;
	for (int i = 1; i < s.size(); i++){
		if ((s[i] == 'R' and s[i - 1] == 'U') or (s[i] == 'U' and s[i - 1] == 'R')){
			cnt ++;
			i ++;
		}
	}
	cout << n - cnt << endl;
}