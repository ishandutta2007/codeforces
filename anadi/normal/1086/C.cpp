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
const LL INF = 1e18 + 9LL;

int n, k;
string s, a, b;

void write(string ans){
	cout << "YES\n";
	cout << ans << "\n";
}

void prepare(vector <int> where){
	vector <bool> is(k, false);
	for(int i = 0; i < k; ++i)
		if(where[i] >= 0)
			is[where[i]] = true;
	
	vector <int> Left;
	for(int i = 0; i < k; ++i)
		if(!is[i])
			Left.push_back(i);
	
	string ans;
	for(int i = 0; i < k; ++i){
		if(where[i] == -1){
			where[i] = Left.back();
			Left.pop_back();
		}
		
		ans.push_back('a' + where[i]);
	}
	
	write(ans);
}

bool check(string fs, string fa, int t, bool type){
	vector <bool> was(k, false);
	vector <int> where(k, -1);

	for(int i = 0; i <= t; ++i){
		int cur = fs[i] - 'a';
		int nxt = fa[i] - 'a';

		if(where[cur] == -1){
			if(was[nxt])
				return false;

			where[cur] = nxt;
			was[nxt] = true;
		}

		if(where[cur] != nxt)
			return false;
	}
	
	for(int i = t + 1; i < n; ++i){
		int cur = fs[i] - 'a';
		int nxt = fa[i] - 'a';

		if(where[cur] != -1){
			if(type && where[cur] > nxt){
				prepare(where);
				return true;
			}
			
			if(!type && where[cur] < nxt){
				prepare(where);
				return true;
			}
			
			if(type && where[cur] < nxt)	return false;
			if(!type && where[cur] > nxt)	return false;			
			continue;
		}
		
		int id = -1;
		if(type){
			for(int j = nxt + 1; j < k; ++j)
				if(!was[j])
					id = j;
		}
		else{
			for(int j = 0; j < nxt; ++j)
				if(!was[j])
					id = j;
		}
		
		if(id != -1){
			where[cur] = id;
			prepare(where);
			return true;
		}
		
		if(was[nxt])
			return false;
		
		where[cur] = nxt;
		was[nxt] = true;
	}
	
	prepare(where);
	return true;
}

void solve(){
	cin >> k;
	cin >> s >> a >> b;
	n = s.size();
	
	int diff = n;
	for(int i = 0; i < n; ++i)
		if(a[i] != b[i]){
			diff = i;
			break;
		}
	
	bool poss = true;
	vector <bool> was(k, false);
	vector <int> where(k, -1);

	for(int i = 0; i < diff; ++i){
		int cur = s[i] - 'a';
		int nxt = a[i] - 'a';

		if(where[cur] == -1){
			if(was[nxt])
				poss = false;
			
			where[cur] = nxt;
			was[nxt] = true;
		}

		if(where[cur] != nxt)
			poss = false;
	}
	
	if(poss && diff == n){
		prepare(where);
		return;
	}
		
	if(diff == n){
		cout << "NO\n";
		return;
	}
		
	if(poss){
		int cur = s[diff] - 'a';
		int nxt = a[diff] - 'a';
		int nxt2 = b[diff] - 'a';
		
		if(nxt2 - nxt > 1){
			if(nxt < where[cur] && where[cur] < nxt2){
				prepare(where);
				return;
			}
			
			if(where[cur] == -1){
				int id = -1;
				for(int i = nxt + 1; i < nxt2; ++i)
					if(!was[i])
						id = i;
				
				if(id != -1){
					where[cur] = id;
					prepare(where);
					return;
				}
			}
		}
	}
	
	if(check(s, a, diff, true))
		return;
	
	if(check(s, b, diff, false))
		return;
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);

	int cases;
	cin >> cases;
	
	while(cases--)
		solve();
	return 0;
}