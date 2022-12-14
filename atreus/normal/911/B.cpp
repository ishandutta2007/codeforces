#include <iostream>
#include <cstring>
#include <algorithm>
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

const int maxn = 1e5 + 100;
int a[maxn];
vector <int> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = a + b; i >= 1; i--){
		int k = a / i;
		int l = b / i;
		if (k + l >= n and k > 0 and l > 0)
			return cout << i << endl, 0;
	}
}