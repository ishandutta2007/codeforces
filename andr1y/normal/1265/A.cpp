#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
char get(char n1, char n2){
	char x = 'a';
	while(x == n1 || x == n2) x++;
	return x;
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		bool ok = 1;
		for(ll i =1;i<s.length();i++) if(s[i] == s[i-1] && s[i] != '?') ok = 0;
		if(!ok){
			cout << -1 << endl;
		}else{
			for(ll i = 1;i<s.length()-1;i++){
				if(s[i] == '?'){
					if(s[i+1] == '?'){
						s[i] = get(s[i-1], 'z');
					}else{
						s[i] = get(s[i-1], s[i+1]);
					}
				}
			}
			if(s[0] == '?'){
				if(s.length() > 1) s[0] = get(s[1], 'z');
				else s[0] = 'a';
			}
			if(s[s.length()-1] == '?'){
				if(s.length() > 1) s[s.length()-1] = get(s[s.length()-2], 'z');
				else s[s.length()-1] = 'a';
			}
			cout << s << endl;
		}
	}
}