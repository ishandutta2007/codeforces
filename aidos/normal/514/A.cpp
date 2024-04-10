#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define forit(it, v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)

typedef pair <int, int > pii;
typedef vector <int> vi;
typedef long long ll;

int main(){
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	string s;
	cin >>s;
	int n = s.size();
	int cur = 0;
	if(s[0] == '9') cur = 1;
	for(int i = cur; i < n; i++){
		int t = s[i] - '0';
		if( 9-t < t) s[i] = (char)('9' - s[i] + '0');
	}
	cout << s << endl;



	#ifdef LOCAL
	cerr << 1.0 * clock()/CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}