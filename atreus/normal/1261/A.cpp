#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

string s;
vector<pair<int,int> > ops;

void Rev(int l, int r){
	ops.push_back({l + 1, r + 1});
	reverse(s.begin() + l, s.begin() + r + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, k;
		cin >> n >> k >> s;
		int cnt = n / 2;
		for (int i = 0; i < n and cnt; i++){
			if (s[i] != '('){
				for (int j = i + 1; j < n; j++){
					if (s[j] == '('){
						Rev(i, j);
						break;
					}
				}
			}
			if (k > 1){
				if (s[i + 1] != ')'){
					for (int j = i + 2; j < n; j++){
						if (s[j] == ')'){
							Rev(i + 1, j);
							break;
						}
					}
				}
				k --;
				i ++;
				cnt --;
				continue;
			}
			cnt --;
		}
		cout << ops.size() << endl;
		for (auto it : ops)
			cout << it.first << " " << it.second << endl;
		ops.clear();
	}
}