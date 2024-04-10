#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 107;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
string in[N];

string rv(int t){
	string ret = in[t];
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> in[i];
	
	int another = -1;
	vector <int> idx;

	for(int i = 1; i <= n; ++i){
		if(rv(i) == in[i]){
			another = i;
			continue;
		}

		for(int j = i + 1; j <= n; ++j)
			if(rv(j) == in[i]){
				idx.push_back(i);
				idx.push_back(j);
				break;
			}
	}
	
	string ans;
	for(int j = 0; j < (int)idx.size(); j += 2)
		ans = ans + in[idx[j]];
	
	if(another != -1)
		ans = ans + in[another];
	
	reverse(idx.begin(), idx.end());
	for(int j = 0; j < (int)idx.size(); j += 2)
		ans = ans + in[idx[j]];
	
	cout << ans.size() << "\n";
	cout << ans << "\n";
	return 0;
}