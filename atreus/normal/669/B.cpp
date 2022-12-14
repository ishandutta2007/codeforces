#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

string s;
int a[maxn];
int n;
bool visited[maxn];

void dfs(int v){
	if (v < 0 or v >= n){
		cout << "FINITE\n";
		exit(0);
	}
	if (visited[v] == 1){
		cout << "INFINITE\n";
		exit(0);
	}
	visited[v] = 1;
	if (s[v] == '>')
		dfs(v + a[v]);
	else
		dfs(v - a[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dfs(0);
}