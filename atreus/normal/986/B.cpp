#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 50;
bool visited[maxn];
vector <int> v[maxn];

void dfs (int u){
	visited[u] = 1;
	for (auto w : v[u])
		if (!visited[w])
			dfs (w);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		v[a].PB (i);
		v[i].PB (a);
	}
	int cnt = n;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			dfs (i);
			cnt --;
		}
	}
	cnt %= 2;
	if (3 * n % 2 == cnt)
		cout << "Petr" << endl;
	else
		cout << "Um_nik" << endl;
}