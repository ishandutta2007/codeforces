//#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	ll n;

	cin >> n;

	vector <ll> d;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			d.push_back(n / i);
		}
	}

	ll g = n;

	for (ll x : d) {
		g = gcd(g, x);
	}

	cout << g << endl;

	//system("pause");
	return 0;
}