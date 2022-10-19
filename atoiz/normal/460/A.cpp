#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define SZ(x) (int)(x).size()

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	int day;
	for (day = 1; n > 0; ++day) {
        --n;
        if (day % m == 0) ++n;
	}
	cout << day - 1 << endl;
}