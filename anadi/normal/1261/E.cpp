#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

vector <string> solve(vector <int> vals) {
	int n = vals.size();
	if(n == 1) {
		if(vals.back())
			return {"1"};
		return {};
	}

	if(vals.back() < n) {
		vector <int> nxt = vals;
		nxt.erase(nxt.begin());
		
		auto ret = solve(nxt);
		for(auto &s: ret) {
			if(vals[0]) {
				s = "1" + s;
				vals[0]--;
			}
			else
				s = "0" + s;
		}
		
		return ret;
	}
	
	if(vals[n - 2] < n) {
		string tmp = string(n - 1, '0') + "1";
		for(int i = 0; i < n - 1 - vals[n - 2]; ++i)
			vals[i]--;
		vals.pop_back();

		auto ret = solve(vals);
		vals.push_back(n);
		
		for(int i = 0; i < n - 1 - vals[n - 2]; ++i) {
			string cur = tmp;
			cur[i] = '1';

			ret.push_back(cur);
			vals[n - 1]--;
		}
		
		for(auto &s: ret)
			if((int)s.size() < n) {
				if(vals[n - 1]) {
					s.push_back('1');
					vals[n - 1]--;
				}
				else
					s.push_back('0');
			}
		
		if(vals[n - 1])
			ret.push_back(tmp);
		return ret;
	}
	
	string to_add;
	for(int i = 0; i < n; ++i)
		if(vals[i] < n || i == n - 1)
			to_add.push_back('0');
		else {
			vals[i]--;
			to_add.push_back('1');
		}
	
	vals.pop_back();
	auto ret = solve(vals);
	
	for(auto &s: ret) {
		s.push_back('1');
		vals[n - 1]--;
	}
	
	if(vals[n - 1])
		ret.push_back(string(n - 1, '0') + "1");

	ret.push_back(to_add);
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	
	vector <int> input(n);
	for(auto &v: input)
		scanf("%d", &v);
	
	vector <int> vals = input;
	sort(vals.begin(), vals.end());

	auto ans = solve(vals);
	printf("%d\n", (int)ans.size());
	
	vector <int> id(n, -1);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			if(vals[i] == input[j] && id[j] == -1) {
				id[j] = i;
				break;
			}
	}
	
	for(auto &s: ans) {
		for(int i = 0; i < n; ++i)
			printf("%c", s[id[i]]);
		puts("");
	}

	return 0;
}