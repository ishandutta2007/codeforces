
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


long long mod = 1000000007;
int main()
{
	
		int n;
		cin >> n ;
		map<int, int> v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			int ct = 0;
			while (x % 2 == 0) {
				x /= 2;
				ct++;
			}
			v[ct]++;
		}
		long long answer = 0;
		long long total = n;
		vector<long long> twos = { 1 };
		for (int i = 0; i < n + 1; i++) {
			twos.push_back((twos.back() * 2) % mod);
		}

		answer += (twos[total - v[0]]) * (twos[v[0]]-1);
		answer %= mod;
		total -= v[0];

		v.erase(0);
		for (auto p : v) {
			total -= p.second;
			long long cur = twos[p.second - 1] - 1;
			answer += (cur * twos[total]) % mod;
			answer %= mod;
			
		}
		cout << answer << endl;
	

}