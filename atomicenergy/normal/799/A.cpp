#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;





int main() {
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int y = (((n-1)/k)+1);
	if(t*(y-1) > d) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}