// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int cnt[30];

char GT(int i){
	return (char)(i + 'a');
}

int Main(){
	int n;
	str s;
	cin >> s;
	n = s.size();
	memset(cnt, 0, sizeof cnt);
	for(auto x : s){
		cnt[x - 'a'] ++;
	}
	int c1 = 0;
	for(int i = 0; i < 26; i++)
		if(cnt[i] > 0) c1 ++;
	// n
	if(c1 == 1)
		return cout << s << '\n', 0;
	// 0
	for(int i = 0; i < 26; i++){
		if(cnt[i] != 1) continue;
		cout << GT(i);
		for(int j = 0; j < 26; j++){
			if(j == i) continue;
			for(int k = 0; k < cnt[j]; k++) cout << GT(j);
		}
		cout << '\n';
		return 0;
	}
	int idx = -1;
	for(int i = 0; i < 26; i++) if(cnt[i]){
		idx = i;
		break;
	}
	// debug(idx);
	if(cnt[idx] <= 1 + (n / 2)){
		cout << GT(idx) << GT(idx);
		cnt[idx] -= 2;
		for(int j = idx + 1; j < 26; j++){
			for(int k = 0; k < cnt[j]; k++){
				cout << GT(j);
				if(cnt[idx]){
					cout << GT(idx);
					cnt[idx] --;
				}
			}
		}
		cout << '\n';
		return 0;
	}
	str res = ""; res += GT(idx);
	int i2 = idx;
	for(int i = idx + 1; i < 26; i++){
		if(cnt[i]){
			i2 = i;
			break;
		}
	}
	// cerr << "^^ " << idx << ' ' << i2 << '\n';
	res += GT(i2);
	cnt[idx] --;
	cnt[i2] --;
	for(int l = 2; l < n; l++){
		int gd = -1;
		for(int c = 0; c < 26; c++){
			if(cnt[c] == 0) continue;
			if(c == i2 && res.back() == res[0]) continue;
			if(c != idx){
				gd = c;
				break;
			}
			if(cnt[i2] == 0){
				gd = c;
				break;
			}
			int fl = 0;
			for(int k = 0; k < 26; k++){
				if(k != idx && k != i2 && cnt[k] > 0){
					fl = 1;
				}
			}
			if(fl == 1){
				gd = c;
				break;
			}
		}
		assert(gd != -1);
		res += GT(gd);
		cnt[gd] --;
	}
	cout << res << '\n';
	// cout << "-1\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		Main();
	}
	return 0;
}
/*
1
aaaaaaaabbbcc

*/