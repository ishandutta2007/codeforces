#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int m;
	string s;
	cin >> m >> s;
	int n = sz(s);
	set<pair<int,char>> q;
	q.insert(mp(-1,'A'));
	q.insert(mp(n,'A'));
	for(char c = 'a'; c <= 'z'; c++) {
		for(int i = 0; i < n; i++)
			if(s[i] == c)
				q.insert(mp(i, c));
		bool bre = true;
		for(auto it = q.begin(); it != q.end() && bre; it++) {
			auto pr = it; pr--;
			if(it != q.begin() && (*it).ff - (*pr).ff - 1 >= m)
				bre = false;
		}
		if(bre) {
			for(auto it = q.begin(); it != q.end(); it++)
				if((*it).ss == c) {
					auto pr = it, ne = it;
					pr--; ne++;
					if((*ne).ff - (*pr).ff - 1 < m) {
						q.erase(it);
						it = pr;
					}
				}
			break;
		}
	}
	vector<char> ans;
	for(auto w : q)
		if(w.ss != 'A')
			ans.pb(w.ss);
	sort(all(ans));
	for(char c : ans)
		cout << c;
}