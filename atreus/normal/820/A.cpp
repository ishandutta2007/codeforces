#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 2e5 + 100;
vector <int> v[maxn];
bool visited[maxn];
int mark, chang[maxn], a[maxn], p[maxn];
ll ans;

int main(){
	ios_base::sync_with_stdio(false);
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int t = 0;
	int page = 0;
	int v = v0;
	while (page < c){
		t ++;
		if (t > 1)
			page -= l;
		page += v;
		v += a;
		v = min(v, v1);
	}
	cout << t << endl;
}