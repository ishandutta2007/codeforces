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
    vector<int> a(n);
    vector<vector<int>> f(n + 1);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	a[i] = n - a[i];
    }

    for (int i = 0; i < n; ++i) {
    	f[a[i]].push_back(i);
    }

    vector<int> b(n);
    int id = 0;
    for (int i = 1; i <= n; ++i) {
    	if (sz(f[i]) % i != 0) {
    		cout << "Impossible" << endl;
    		return 0;
    	}

    	for (int j = 0; j < sz(f[i]); ++j) {
    		if (j % i == 0) {
    			++id;
    		}
    		b[f[i][j]] = id;
    	}
    }
   	
   	cout << "Possible" << endl;
   	for (int i = 0; i < n; ++i) {
   		cout << b[i] << " ";
   	}
   	cout << endl;




}