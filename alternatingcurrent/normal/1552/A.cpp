#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
string s;
string t;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> s;
		t = s;
		sort(t.begin(), t.end());
		int cnt = 0;
		rep(i, (int)s.size())
			if(s[i] != t[i])
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}