#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

vector <char> sa, sb;

void solve(){
	string s;
	cin >> s;
	
	for(auto c: s){
		int t = c - '0';
		if(t & 1)
			sa.push_back(c);
		else
			sb.push_back(c);
	}
	
	reverse(sa.begin(), sa.end());
	reverse(sb.begin(), sb.end());
	
	while(sa.size() + sb.size()){
		if(sa.size() == 0){
			cout << sb.back();
			sb.pop_back();
			continue;
		}

		if(sb.size() == 0){
			cout << sa.back();
			sa.pop_back();
			continue;
		}
		
		if(sa.back() < sb.back()){
			cout << sa.back();
			sa.pop_back();
		}
		else{
			cout << sb.back();
			sb.pop_back();
		}
	}
	
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases;
	cin >> cases;
	
	while(cases--)
		solve();
	return 0;
}