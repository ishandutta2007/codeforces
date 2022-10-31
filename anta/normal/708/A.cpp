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
		int i = 0;
		while(i + 1 != s.size() && s[i] == 'a')
			++ i;
		do {
			s[i] = 'a' + (s[i] - 'a' + 25) % 26;
			++ i;
		} while(i != s.size() && s[i] != 'a');
		puts(s.c_str());
	}
	return 0;
}