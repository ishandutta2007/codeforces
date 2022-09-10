#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 19LL;

string s;
bool type;
int pl, mn;

vector <PII> merge(vector <PII> a, vector <PII> b){
	vector <PII> ret;
	ret.resize(min((int)a.size() + (int)b.size() - 1, type ? pl : mn) + 1);
	
	for(int i = 0; i < (int)ret.size(); ++i){
		ret[i] = {MX, -MX};
		for(int j = 0; j < (int)a.size(); ++j){
			if(j > i)
				break;
			
			if(i - j < (int)b.size()){
				ret[i].st = min(ret[i].st, a[j].st + (type ? -b[i - j].nd : b[i - j].st));
				ret[i].nd = max(ret[i].nd, a[j].nd + (type ? -b[i - j].st : b[i - j].nd));
			}
			
			if(i - j - 1 < (int)b.size() && i >= j + 1){
				ret[i].st = min(ret[i].st, a[j].st + (type ? b[i - j - 1].st : -b[i - j - 1].nd));
				ret[i].nd = max(ret[i].nd, a[j].nd + (type ? b[i - j - 1].nd : -b[i - j - 1].st));
			}
		}
	}
	
	return ret;
}

vector <PII> solve(int l, int r){
	vector <PII> ret;
	if(l == r){
		ret.resize(1);
		ret[0] = {s[l] - '0', s[r] - '0'};
		return ret;
	}
	
	for(int i = l; i <= r; ++i){
		if(s[i] == '?')
			continue;

		if(s[i] == '('){
			int cur = 1, pos = i + 1;
			while(cur > 0){
				if(s[pos] == '(')
					++cur;
				else if(s[pos] == ')')
					--cur;
				++pos;
			}
			
			if(ret.size())
				ret = merge(ret, solve(i + 1, pos - 2));
			else
				ret = solve(i + 1, pos - 2);
			i = pos - 1;
			continue;
		}
		
		if(ret.size())
			ret = merge(ret, solve(i, i));
		else
			ret = solve(i, i);
	}
	
//	printf("W %d %d\n", l, r);
//	for(auto v: ret)
//		printf("%d %d\n", v.st, v.nd);
	return ret;
}

int main(){
	cin >> s;
	cin >> pl >> mn;
	type = pl < mn;

	auto ret = solve(0, s.size() - 1);
	printf("%d\n", ret[type ? pl : mn].nd);
	return 0;
}