#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int n;
string s, t;
vector<int> ops;
int L, R, rev;

char get(int idx){
	if (idx == 0)
		idx = L;
	else
		idx = R;
	if (rev == 0)
		return s[idx];
	else{
		if (s[idx] == '0')
			return '1';
		else
			return '0';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--){
		ops.clear();
		cin >> n;
		cin >> s >> t;
		L = 0, R = n-1;
		rev = 0;
		for (int i = (int)s.size() - 1; i >= 0; i--){
			if (get(i) == t[i]){
				if (R > L)
					R --;
				else
					R ++;
				continue;
			}
			if (get(0) == t[i])
				ops.push_back(1);
			ops.push_back(i+1);
			swap(L,R);
			rev ^= 1;
			if (R > L)
				R --;
			else
				R ++;
		}
		cout << ops.size() << " ";
		for (auto it : ops)
			cout << it << " ";
		cout << '\n';
	}
}