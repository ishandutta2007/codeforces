#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define y1 ngsdf
#define sqr(a) ( (a) * (a) )
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const ld E = 1e-9;
const int MAX = 1e6 + 1;

bool check(string s1, string s2, int begin = 0){
	if(s1.length() + begin < s2.length())
		return false;
	for(int i = 0; i < (int) s2.length(); i++)
		if(s1[i + begin] != s2[i])
			return false;
	return true;
}

int main() {

	string s;
	cin >> s;

	int g = 0;

	if(check(s, "http")){
		cout << "http://";
		g = 4;
	}else{
		cout << "ftp://";
		g = 3;
	}
	cout << s[g++];
	for(int i = g; i < (int) s.length(); i++){
		if(check(s, "ru", g)){
			g += 2;
			cout << ".ru";
			break;
		}else{
			g++;
			cout << s[i];
		}
	}

	if(g != (int) s.length())
		cout << "/";
	for(int i = g; i < (int) s.length(); i++)
		cout << s[i];

}