#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , cnt[26];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		fill(cnt , cnt + 26 , 0);
		cin >> s; n = s.size();
		int flag = 0;
		for(int i = 0 ; i < n ; i++){
			cnt[s[i] - 97]++;
			if(s[i] != s[0])	flag = 1;
		}
		if(flag == 0){
			cout << s << endl;
			continue;
		}
		int ind = -1 , mn = 30;
		for(int i = 0 ; i < 26 ; i++){
			if(cnt[i])	mn = min(mn , i);
			if(cnt[i] == 1){
				ind = i;
				break;
			}
		}
		if(ind != -1){
			cout << char('a' + ind);
			cnt[ind]--;
			for(int i = 0 ; i < 26 ; i++){
				for(int j = 0 ; j < cnt[i] ; j++){
					cout << char('a' + i);
				}
			}
			cout << endl;
			continue;
		}
		int res = 30 , diff = 0;
		for(int i = 0 ; i < 26 ; i++){
			if(1 <= cnt[i] && cnt[i] <= n / 2 + 1)	res = min(res , i);
			diff += (cnt[i] != 0);
		}
		if(res != mn && diff == 2){
			cout << char('a' + mn);
			cnt[mn]--;
			for(int i = 25 ; i >= 0 ; i--){
				for(int j = 0 ; j < cnt[i] ; j++){
					cout << char('a' + i);
				}
			}
			cout << endl;
			continue;
		}
		cout << char('a' + mn) << char('a' + res);
		flag = (res == mn); cnt[res]--; cnt[mn]--;
		for(int i = n - 2 ; i > 0 ; i--){
			int cur = 0;
			for(int j = 0 ; j < 26 ; j++){
				if(flag == 1 && j == res)	continue;
				if(cnt[j]){
					cur = j;
					break;
				}
			}
			cout << char('a' + cur);
			cnt[cur]--;
			flag = (cur == mn);
		}
		cout << endl;
	}

    return 0;
}
/*

*/