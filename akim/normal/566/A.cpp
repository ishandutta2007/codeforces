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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1000100;

struct bor {
	int nx[26];
	vector<int> a, b;
	int stp;
};

int sz = 1;
bor br[maxn];
string s;
bool useda[maxn], usedb[maxn];
int ans[maxn];

vector<int> bf;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		int pos = 0;
		br[0].a.pb(i);
		for(int f = 0; f < (int)s.length(); f++) {
			int b = s[f] - 'a';
			if(br[pos].nx[b] == 0) {
				br[pos].nx[b] = sz;
				br[sz].stp = br[pos].stp + 1;
				sz++;
			}
			pos = br[pos].nx[b];
			br[pos].a.pb(i);
		}
	}
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		int pos = 0;
		br[0].b.pb(i);
		for(int f = 0; f < (int)s.length(); f++) {
			int b = s[f] - 'a';
			if(br[pos].nx[b] == 0) {
				br[pos].nx[b] = sz;
				br[sz].stp = br[pos].stp + 1;
				sz++;
			}
			pos = br[pos].nx[b];
			br[pos].b.pb(i);
		}
	}

	bf.pb(0);
	for(int i = 0; i < (int)bf.size(); i++) {
		int pos = bf[i];
		for(int f = 0; f < 26; f++) {
			if(br[pos].nx[f] != 0) {
				bf.pb(br[pos].nx[f]);
			}
		}
	}
	ll ans2 = 0;
	while(!bf.empty()) {
		int pos = bf.back();
		bf.ppb();
		while(1) {
			while(!br[pos].a.empty() && useda[br[pos].a.back()]) {
				br[pos].a.ppb();
			}
			if(br[pos].a.empty()) {
				break;
			}
			while(!br[pos].b.empty() && usedb[br[pos].b.back()]) {
				br[pos].b.ppb();
			}
			if(br[pos].b.empty()) {
				break;
			}
			ans[br[pos].a.back()] = br[pos].b.back();
			ans2 += br[pos].stp;
			useda[br[pos].a.back()] = 1;
			usedb[br[pos].b.back()] = 1;
		}
	}


	printf("%I64d\n", ans2);
	for(int i = 0; i < n; i++) {
		printf("%d %d\n", i + 1, ans[i] + 1);
	}


	return(0);
}

// by Kim Andrey