#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int maxn = 3e3 + 100;
vector <int> v[maxn], idx, per;
bool visited[maxn];
string s[maxn];
int p[maxn];

void dfs (int u){
	visited[u] = 1;
	idx.PB(u);
	per.PB(p[u]);
	for (auto w : v[u])
		if (!visited[w])
			dfs (w);
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++){
		for (int j = i; j < n; j++){
			if (s[i][j] == '1'){
				v[i].PB(j + 1);
				v[j + 1].PB(i);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			dfs (i);
			sort (idx.begin(), idx.end());
			sort (per.begin(), per.end());
			for (int i = 0; i < idx.size(); i++)
				p[idx[i]] = per[i];
			per.clear();
			idx.clear();
		}
	}
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
}