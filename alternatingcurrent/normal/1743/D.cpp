#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

string s;

string ans;

void calc(int d){
	string nxt = s;
	for(int i = (int)s.size()-1; i >= d; --i)
		if(s[i-d] == '1')
			nxt[i] = '1';
	if(nxt > ans)
		ans = nxt;
}

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n >> s;
	ans = s;
	
	int st = 0;
	while(st < n && s[st] == '0') ++st;
	
	int t = st;
	while(t < n && s[t] == '1') ++t;
	
	for(int d = 1; d <= t - st; ++d)
		calc(d);
	
	st = 0;
	while(st < (int)ans.size()-1 && ans[st] == '0') ++st;
	for(int i = st; i < (int)ans.size(); ++i)
		cout << ans[i];
	cout << endl;
	
	return 0;
}