#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");


   	int n;
   	cin >> n;
   	vector<ll> x(n);

   	for (int i = 1; i < n; i += 2) {
   		cin >> x[i];
   	}

   	ll cur = 0;

   	for (int i = 0; i < n; i += 2) {
   		ll m = x[i + 1];

   		vector<int> d;
   		for (int i = 1; i * i <= m; ++i) {
   			if (m % i == 0) {
   				d.push_back(i);
   			}	
   		}	

   		x[i] = 1e18;  
   		bool ok = false;
   		for (int k : d) {
   			if ((k + m / k) & 1) {
   				continue;
   			}

   			ll u = (m / k - k) / 2;

   			if (cur < u * u) {
   				x[i] = min(x[i], u * u - cur);
   				ok = true;
   			}
   		}

   		if (!ok) {
   			cout << "No" << endl;
   			return 0;
   		}

   		cur += x[i] + x[i + 1];
   	}

   	cout << "Yes" << endl;
   	for (int i = 0; i < n; ++i) {
   		cout << x[i] << " ";
   	}
   	cout << endl;


}