#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define F first
#define S second
using namespace std;

const int maxn = 1e5 + 100;
bool isleaf[maxn];
int fa[maxn], deg[maxn];

int main (){
	memset (isleaf, 1, sizeof isleaf);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		cin >> fa[i];
		isleaf[fa[i]] = false;
	}
	for (int i = 2; i <= n; i++)
		if (isleaf[i])
			deg[fa[i]] ++;
	for (int i = 1; i <= n; i++)
		if (isleaf[i] == false and deg[i] < 3)
			return cout << "No" << endl, 0;
	cout << "Yes" << endl;
}