#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5 + 5;
 
string s[20];
map<string, bool> mp, inall;
 
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		vector<string> a;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			inall[s[i]] = true;
		}
		for (int i = 0; i < n; i++){
			if (mp.count(s[i]) == false){
				mp[s[i]] = true;
				a.push_back(s[i]);
			}
			else{
				cnt ++;
				s[i][0] = '0';
				while (mp.count(s[i]) == true or inall.count(s[i]) == true){
					int k = (int)(s[i][0] - '0');
					k ++;
					s[i][0] = (char)(k + '0');
				}
				mp[s[i]] = true;
				a.push_back(s[i]);
			}
		}
		cout << cnt << '\n';
		for (auto it : a)
			cout << it << '\n';
		mp.clear();
		inall.clear();
	}
}