#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1200 + 10;
const ld eps = 1e-6;

string getBracket(int n, int mask){
	string s;
	for (int i = 0; i < n; i++){
		if (mask & (1 << i))
			s += '(';
		else
			s += ')';
	}
	return s;
}

vector<pair<pair<ld,ld>,string>> mp[20];

ld getArea(string s){
	int h = 0;
	ld ret = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			ret += (2.*h+1)/2;
			h++;
		}
		else{
			ret += (2.*h-1)/2;
			h--;
		}
	}
	return ret;
}

pair<ld,ld> getSpecialCOM(int h){
	ld Area = h;
	pair<ld,ld> COM = {0.5, h/2.};
	ld a = 0.5;
	pair<ld,ld> c = {2./3., h + 1./3.};
	return {(h*COM.first + a*c.first) / (Area+a), (h*COM.second + a*c.second) / (Area+a)};
}

pair<ld,ld> getCOM(string s){
	ld Area = 0;
	pair<ld,ld> COM = {0, 0};
	int cnt = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			pair<ld,ld> c = getSpecialCOM(cnt);
			c.first += i;
			ld a = (2.*cnt+1)/2;
			cnt++;
			COM.first = (c.first*a + COM.first*Area) / (a+Area);
			COM.second = (c.second*a + COM.second*Area) / (a+Area);
			Area += a;
		}
		else{
			cnt--;
			pair<ld,ld> c = getSpecialCOM(cnt);
			c.first = i+1. - c.first;
			ld a = (2.*cnt+1)/2;
			COM.first = (c.first*a + COM.first*Area) / (a+Area);
			COM.second = (c.second*a + COM.second*Area) / (a+Area);
			Area += a;
		}
	}
	return COM;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	ld X, Y;
	cin >> n >> X >> Y;
	int chert = 0;
	for (int mask = 0; mask < (1 << n/2); mask++){
		int op = __builtin_popcount(mask);
		int cl = n/2 - op;
		string s = getBracket(n/2, mask);
			int now = 0;
		bool flag = false;
		for (int i = 0; i < n/2; i++){
			if (s[i] == ')' and now == 0){
				flag = true;
				break;
			}
			if (s[i] == '(')
				now++;
			else
				now--;
		}
		if (!flag){
			chert++;
			ld Area = getArea(s);
			pair<ld,ld> COM = getCOM(s);
			mp[op-cl].push_back({{Area*COM.first-Area*X, Area*COM.second-Area*Y}, s});
		}
	}
	for (int i = 0; i < 20; i++)
		sort(mp[i].begin(), mp[i].end());
	for (int mask = 0; mask < (1 << n/2); mask++){
		int op = __builtin_popcount(mask);
		int cl = n/2 - op;
		string s = getBracket(n/2, mask);
			int now = 0;
		bool flag = false;
		for (int i = 0; i < n/2; i++){
			if (s[i] == ')' and now == 0){
				flag = true;
				break;
			}
			if (s[i] == '(')
				now++;
			else
				now--;
		}
		if (!flag){
			ld Area = getArea(s);
			pair<ld,ld> COM = getCOM(s);
			COM.first = n - COM.first;
			ld F = -Area*COM.first+Area*X;
			ld S = -Area*COM.second+Area*Y;
			int lo = -1, hi = mp[op-cl].size();
			while (hi - lo > 1){
				int mid = (lo+hi) >> 1;
				if (mp[op-cl][mid].first.first + eps < F)
					lo = mid;
				else
					hi = mid;
			}
			for (int i = hi; i < mp[op-cl].size() && mp[op-cl][i].first.first < F + eps; i++){
				if (abs(mp[op-cl][i].first.second - S) <= eps){	
					cout << mp[op-cl][i].second;
					reverse(s.begin(),s.end());
					for (int i = 0; i < s.size(); i++)
						if (s[i] == '(')
							s[i] = ')';
						else
							s[i] = '(';
					cout << s << endl;
					return 0;
				}
			}
		}
	}

}