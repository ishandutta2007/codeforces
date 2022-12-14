#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define MP make_pair
#define PB push_back
#define L first
#define R second

typedef pair<int, int> pie;
typedef long long ll;

void f(int n, int inx){
	for (int i = 2; i <= n; i++)
		cout << 1 + inx << " " << i + inx << endl;
	for (int i = 2; i <= n + 1; i++)
		cout << inx + n + 2 << " " << inx + i << endl;
	for (int i = 2; i <= n; i++)
		cout << inx + n + 1 << " " << inx + i << endl;
	for (int i = 2; i <= n; i++){
		if (i % 2 == 0){
			for (int j = i + 2; j <= n; j++)
				cout << inx + i << " " << inx + j << endl;
		}
		else{
			for (int j = i + 1; j <= n; j++)
				cout << inx + i << " " << inx + j << endl;
		}
	}
}

int main(){
	int n;
	cin >> n;
	if (n % 2 == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (n == 1){
		cout << 2 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		return 0;
	}
	cout << 2 * n + 4 << " " << n * (n + 2) << endl;
	f(n, 0);
	cout << 1 << " " << n + 3 << endl;
	f(n, n + 2);
}