#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int cnt[33];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		memset(cnt, 0, sizeof(cnt));
		string s;
		cin >> s;
		int n = (int)s.size();
		rep(i, n)
			cnt[s[i] - 'a']++;
		bool ok = 1;
		rep(i, n)
			if(cnt[i] != 1){
				ok = 0;
				break;
			}
		if(!ok){
			cout << "NO" << endl;
			continue;
		}
		int posl = 0, posr = 0;
		rep(i, n)
			if(s[i] == 'a')
				posl = posr = i;
		rep(cnt, n){
			if(posl && s[posl - 1] == (char)('a' + cnt + 1))
				posl--;
			if(posr < n - 1 && s[posr + 1] == (char)('a' + cnt + 1))
				posr++;
		}
		if(posl > 0 || posr < (int)s.size() - 1)
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
	return 0;
}