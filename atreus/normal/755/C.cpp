#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e4 + 100;
vector <int> v[maxn];
int a[maxn];
bool visited[maxn];

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
		cin >> a[i];
		v[i].PB(a[i]);
		v[a[i]].PB(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			dfs (i);
			cnt ++;
		}
	}
	cout << cnt << endl;
}