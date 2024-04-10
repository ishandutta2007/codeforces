#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAX1 = 2e5+7,
	     MOD = 1e9+7;

ll n;
char ch;
string s;

bool palin(string s){
	for (int i = 0; i < s.size()/2; ++i){
		if (s[i] != s[s.size()-i-1])	return false;
	}
	return true;
}

int main(){
	fast_io;
	cin >> s;
	for (int i = 0; i < s.size(); ++i){
		for (int j = 0; j < 26; ++j){
			if (j == int(s[i])-97)	continue;
			ch = s[i];
			s[i] = char(97+j);
			if (palin(s)){
				cout << "YES";
				return 0;
			}
			s[i] = ch;
		}
	}
	cout << "NO";
    return 0;
}
/*                     now or never                         */