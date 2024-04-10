#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ll;

int main()
{
    ll a, b;
    int k;
    cin >> a >> b >> k;

    if (a / 360360 == b / 360360) {
		vector<int> v(360361, 999999);
		v[b % 360360] = 0;
		for (int i = b % 360360 + 1; i <= a % 360360; ++i) {
			v[i] = v[i-1] + 1;
			for (int x = 2; x <= k; ++x) {
				// cout << i << ": " << v[i] << ", " << v[i - i % x] + 1 << endl;
				v[i] = min(v[i], v[i - i % x] + 1);
			}
			// cout << "v["<< i << "] = " << v[i] << endl;
		}
		cout << v[a % 360360] << endl;
		return 0;
    }

    vector<int> v(360361);
    v[0] = 0;
    for (int i = 1; i < v.size(); ++i) {
		v[i] = v[i-1] + 1;
		for (int x = 2; x <= k; ++x) {
			v[i] = min(v[i], v[i - i % x] + 1);
		}
    }

    ll cnt = 0;
    cnt += v[a % 360360];
    a -= a % 360360;

    ll c = (b % 360360 == 0 ? b : b + 360360 - b % 360360);
	cnt += (a - c) / 360360 * v[360360];

	if (b % 360360 == 0) {
		cout << cnt << endl;
		return 0;
	}

	v.assign(360361, 999999);
	v[b % 360360] = 0;
	for (int i = b % 360360 + 1; i <= v.size(); ++i) {
		v[i] = v[i-1] + 1;
		for (int x = 2; x <= k; ++x) {
			v[i] = min(v[i], v[i - i % x] + 1);
		}
	}
	cnt += v[360360];

	cout << cnt << endl;
}