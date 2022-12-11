#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);

int x[50][50];
bool pm[50];
string s[110];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		for(int f = i + 1; f < n; f++) {
			bool ok = 0;
			for(int g = 0; g < (int)min(s[i].length(), s[f].length()); g++) {
				if(s[i][g] != s[f][g]) {
					if(x[s[i][g] - 'a'][s[f][g] - 'a'] != -1) {
						x[s[i][g] - 'a'][s[f][g] - 'a'] = 1;
						x[s[f][g] - 'a'][s[i][g] - 'a'] = -1;
//						cout << i << " " << f << "\n";
					} else {
						cout << "Impossible";
						return(0);
					}
					ok = 1;
					break;
				}
			}
			if(!ok) {
				if(s[i].length() >= s[f].length()) {
					cout << "Impossible";
					return(0);
				}
			}
		}
	}
	string ans; ans.clear();
	for(int i = 0; i < 26; i++) {
		bool ok = 0;
		int c = 0;
		for(int f = 0; f < 26; f++) if(!pm[f]) {
			bool nm = 1;
			for(int g = 0; g < 26; g++) if(!pm[g]) {
				if(x[f][g] == -1) {
					nm = 0;
					break;
				}
			}
			if(nm == 1) {
				ok = 1;
				c = f;
				break;
			}
		}
		if(!ok) {
			cout << "Impossible";
			return(0);
		}
		ans += (char)('a' + c);
		pm[c] = 1;
	}
	cout << ans;


	return(0);
}

// by Kim Andrey