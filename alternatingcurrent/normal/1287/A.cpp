#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t, n;
string s;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cin >> s;
		int last = -1, ans = 0;
		rep(i, n){
			if(s[i] == 'A') last = i;
			else {
				if(last >= 0) ans = max(ans, i - last);
			}
		}
		cout << ans << endl;
	}
	return 0;
}