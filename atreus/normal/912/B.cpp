#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <iomanip>

#define PB push_back
#define MP make_pair
#define F first
#define S second

using namespace std;

vector <long long> v;

int main (){
	long long l = 1;
	for (long long i = 1; i <= 63; i ++){
		v.PB(l);
		l *= 2;
	}
	long long n, k;
	cin >> n >> k;
	if (k == 1)
		return cout << n << endl, 0;
	auto idx = upper_bound(v.begin(), v.end(), n);
	cout << *idx - 1 << endl;
}