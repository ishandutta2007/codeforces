#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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
const int maxn = 110;

int preff[maxn];
pair<int, pair<int, int> > predok[maxn][maxn][maxn];
int dp[maxn][maxn][maxn];

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

	string s, t, v;
	getline(cin, s);
	getline(cin, t);
	getline(cin, v);
	int ls = s.length(), lt = t.length(), lv = v.length();
	v += '#';
	for(int i = 1; i < lv + 1; i++) {
		int pos = preff[i - 1];
		while(pos > 0 && v[pos] != v[i]) {
			pos = preff[pos - 1];
		}
		if(v[pos] == v[i]) {
			preff[i] = pos + 1;
		} else {
			preff[i] = 0;
		}
	}

//	for(int i = 0; i < lv; i++) {
//		cout << preff[i] << " ";
//	}

	for(int g = 0; g < lv; g++)
		predok[0][0][g] = mp(-1, mp(0, 0));

	int maxi = 0, maxf = 0, maxg = 0;

	for(int i = 0; i < ls; i++) {
		for(int f = 0; f < lt; f++) {
			for(int g = 0; g < lv; g++) {
				if(dp[i + 1][f][g] <= dp[i][f][g]) {
					dp[i + 1][f][g] = dp[i][f][g];
					predok[i + 1][f][g] = mp(i, mp(f, g));
				}
				if(dp[i][f + 1][g] <= dp[i][f][g]) {
					dp[i][f + 1][g] = dp[i][f][g];
					predok[i][f + 1][g] = mp(i, mp(f, g));
				}
				if(s[i] == t[f]) {
					int pos = g;
					while(pos > 0 && v[pos] != s[i]) {
						pos = preff[pos - 1];
					}
					if(v[pos] == s[i]) {
						pos++;
					} else {
						pos = 0;
					}
					if(dp[i + 1][f + 1][pos] <= dp[i][f][g] + 1) {
						dp[i + 1][f + 1][pos] = dp[i][f][g] + 1;
						predok[i + 1][f + 1][pos] = mp(i, mp(f, g));
					}
				}
			}
		}
	}

	for(int i = 0; i <= ls; i++) {
		for(int f = 0; f <= lt; f++) {
			for(int g = 0; g < lv; g++) {
				if(dp[maxi][maxf][maxg] < dp[i][f][g]) {
					maxi = i;
					maxf = f;
					maxg = g;
				}
			}
		}
	}


	string str; str.clear();
	while(predok[maxi][maxf][maxg].fs != -1) {
//		cout << maxi << " " << maxf << " " << maxg << "\n";
		int i = predok[maxi][maxf][maxg].fs, f = predok[maxi][maxf][maxg].sc.fs, g = predok[maxi][maxf][maxg].sc.sc;
		if(dp[maxi][maxf][maxg] > dp[i][f][g]) {
			str += s[i];
		}
		maxi = i;
		maxf = f;
		maxg = g;
	}
//	cout << maxi << " " << maxf << " " << maxg << "\n";

	reverse(str.begin(), str.end());
	if(str.length() == 0) {
		cout << "0";
	} else {
		cout << str;
	}

	return(0);
}

// by Kim Andrey