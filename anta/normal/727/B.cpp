#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	string s;
	while(cin >> s) {
		for(char &c : s) if(isalpha(c)) c = ' ';
		stringstream ss(s);
		string w;
		ll sum = 0;
		while(ss >> w) {
			if(!(w.size() >= 4 && w[w.size() - 3] == '.'))
				w += ".00";
			ll p = 0;
			for(char c : w) if(isdigit(c))
				p = p * 10 + (c - '0');
			sum += p;
		}
		char buf[100];
		vector<string> v;
		if(sum % 100 != 0) {
			sprintf(buf, "%02d", (int)(sum % 100));
			v.push_back(buf);
		}
		sum /= 100;
		while(sum >= 1000) {
			sprintf(buf, "%03d", (int)(sum % 1000));
			v.push_back(buf);
			sum /= 1000;
		}
		v.push_back(to_string(sum));
		reverse(v.begin(), v.end());
		int i = 0;
		for(string s : v) {
			if(i ++ != 0) putchar('.');
			printf("%s", s.c_str());
		}
		puts("");
	}
	return 0;
}