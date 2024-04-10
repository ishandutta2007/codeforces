# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xk = 320;

string fn1(char a, char b, int t){
	//cout << a << sep << b << sep << t << endl;
	char f;
	if (a != 'a' && b != 'a') f = 'a';
	else if (a != 'b' && b != 'b') f = 'b';
	else f = 'c';
	string ans = "";
	
	if (a == b){
		if (a == 'a'){
			for (int i=0; i<t; i++){
				if (i%2 == 0) ans += 'b';
				else ans += 'c';
			}
		}
		if (a == 'b'){
			for (int i=0; i<t; i++){
				if (i%2 == 0) ans += 'a';
				else ans += 'c';
			}
		}
		if (a == 'c'){
			for (int i=0; i<t; i++){
				if (i%2 == 0) ans += 'b';
				else ans += 'a';
			}
		}
		return ans;
	}
	
	if (t%2 == 1) ans += f;
	for (int i=0; i<t/2; i++) ans += b, ans += a;
	//cout << f << endl;
	return ans;
}

int main(){
	int q;
	cin >> q;
	while (q--){
		string a;
		cin >> a;
		
		string ans = "";
		
		char ls = 'a';
		int t = 0;
		for (int i=0; i<a.size(); i++){
			if (a[i] == '?') t++;
			else{
				ans += fn1(ls, a[i], t);
				t = 0;
				ls = a[i];
				ans += a[i];
			}
		}
		ans += fn1(ls, 'b', t);
		bool fl1 = false;
		for (int i=1; i<a.size(); i++){
			if (a[i] == a[i-1] && a[i] != '?'){
				cout << -1 << endl;
				fl1 = true;
				break;
			}
		}
		
		if (fl1) continue;
		
		cout << ans << endl;
	}
	
	return 0;
}