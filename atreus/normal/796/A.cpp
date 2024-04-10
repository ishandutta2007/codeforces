#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int pri[1000];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> pri[i];
	int dis1 = 10000000, dis2 = 10000000;
	for (int i = m; i <= n; i++){
		if (pri[i] != 0 && pri[i] <= k){
			dis1 = 10 * (i - m);
			break;
		}
	}
	for (int i = m; i >= 1; i--){
		if (pri[i] != 0 && pri[i] <= k){
			dis2 = 10 * (m - i);
			break;
		}
	}
	cout << min(dis1, dis2) << endl;
}