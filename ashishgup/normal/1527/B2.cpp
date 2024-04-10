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
		int alice = 0, bob = 0;
		int cnt = 0, reqd = 0;
		for(auto &it:s)
			cnt += (it == '0');
		string str = s;
		reverse(str.begin(), str.end());
		if(s == str)
		{
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
		else
		{
			if(n % 2 == 0 || (s[n / 2] == '1'))
				cout << "ALICE" << endl;
			else
			{
				if(cnt == 2)
					cout << "DRAW" << endl;
				else
					cout << "ALICE" << endl;
			}
		}
		
	}
	return 0;
}