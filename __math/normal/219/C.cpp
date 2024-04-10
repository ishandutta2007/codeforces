#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <ctime>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

#define FOR(i,n) for(int i = 0 ;i < (n); i++)


int n,k;
string s;

int solve2(char f){
	int ans = 0;
	FOR(i,n){
		if(s[i] != f)
			ans++;
		f = (f == 'A') ? 'B' : 'A';
	}

	return ans;
}

int main()
{
	cin>>n>>k>>s;

	if(k == 2){
		int sa = solve2('A');
		int sb = solve2('B');
		char f = 'A';
		if(sa > sb) f = 'B';
		
		cout << min(sa,sb) << endl;
		FOR(i,n){
			putchar(f);
			f = (f == 'A') ? 'B' : 'A';
		}
		puts("");

	} else {
		int ans = 0;
		for(int i = 1; i < n; i++){
			if(s[i] == s[i-1]){
				ans++;
				char c = 'A';
				if(i == n-1){
					while(s[i-1] == c) 
						c++;
				} else {
					while(s[i-1] == c || s[i+1] == c) 
						c++;
				}
				s[i] = c;
			}
		}
		cout << ans << endl << s << endl;
	}

	return 0;
}