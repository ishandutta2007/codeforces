#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e3 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int cnt = 0;
		for(auto &it:s)
			cnt += (it == '0');
		if(n % 2 == 0 || (s[n / 2] == '1'))
			cout << "BOB" << endl;
		else
		{
			if(cnt == 1)
				cout << "BOB" << endl;
			else
				cout << "ALICE" << endl;
		}
	}
	return 0;
}