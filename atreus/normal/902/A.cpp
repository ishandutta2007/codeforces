#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;
bool cur;
bool mark[maxn];
int b[maxn], a[maxn];

int main(){
	int n, m;
	cin >> n >> m;
	mark[0] = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		if (mark[a[i]]){
			for (int j = a[i] + 1; j <= b[i]; j++)
				mark[j] = 1;
		}
	}
	if (mark[m])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}