#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, a, b, x;
char c = '0', t = '1';
string ans;
int main(){
	cin >> a >> b >> x;
	if(a<b){
		swap(c, t);
		swap(a, b);
	}
	ans += c;
	a--;
	while(x>0){
		if(ans.back()==t) {
			ans += c;
			a--;
		}
		else {
			ans += t;
			b--;
		}
		x--;
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(c == ans[i]){
			while(a>0){
				a--;
				cout << c;
			}
		}
		
		if(t == ans[i]){
			while(b>0){
				b--;
				cout << t;
			}
		}
	}
	return 0;
}