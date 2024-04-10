#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, k;
string s[1515];
map<string, int> cnt;

string get_to(string s1, string s2){
	string ret;
	rep(i, k){
		if(s1[i] == s2[i]) ret += s1[i];
		else {
			if(s1[i] != 'S' && s2[i] != 'S') ret += 'S';
			if(s1[i] != 'E' && s2[i] != 'E') ret += 'E';
			if(s1[i] != 'T' && s2[i] != 'T') ret += 'T';
		}
	}
	return ret;
}

int main(){
	cin >> n >> k;
	rep(i, n) cin >> s[i];
	rep(i, n) cnt[s[i]]++;
	int ans = 0;
	rep(j, n){
		rep(i, j){
			if(s[i] == s[j]) continue;
			string to = get_to(s[i], s[j]);
			ans += cnt[to];
		}
	}
	ans /= 3;
	rep(i, n){
		if(cnt[s[i]] >= 3){
			int num = cnt[s[i]];
			ans += (num * (num-1) * (num-2)) / 6;
			cnt[s[i]] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}