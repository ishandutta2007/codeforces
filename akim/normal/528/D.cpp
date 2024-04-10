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

//#include <bitset>

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
const int maxn = 200100;
const int step = 32;

bool ans[maxn];
//bitset<maxn> bst, bss;
ull bst[maxn / step], bss[maxn / step];
int cnts[maxn];
const string str = "ACGT";

bool srav(int ln) {
	for(int i = 0; i < ln; i++) {
		if((bss[i] & bst[i]) != bst[i]) {
			return(0);
		}
	}
	return(1);
}

void sdvig(int ln) {
	for(int i = 0; i < ln; i++) {
		bss[i] >>= 1;
		bss[i] |= (bss[i + 1] & 1ll) << (step - 1);
	}
}

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

	int ls, lt, k;
	scanf("%d%d%d\n", &ls, &lt, &k);
	for(int i = 0; i < ls - lt + 1; i++) {
		ans[i] = 1;
	}
	string s, t;
	getline(cin, s), getline(cin, t);
	int ln = (lt - 1) / step + 1;
	for(int let = 0; let < 4; let++) {
		for(int i = 0; i < ls; i++) {
			cnts[i] = 0;
		}
		for(int i = 0; i < ln; i++) {
			bst[i] = 0;
			bss[i] = 0;
		}
		for(int i = 0, f = 0, g = 0; i < lt; i++, f++) {
			if(f == step) f = 0, g++;
			bst[g] |= (t[i] == str[let] ? 1ll : 0ll) << f;
//			cout << (t[i] == str[let] ? 1ll : 0) << " ";
//			for(int f = 0; f < ln; f++) {
//				cout << bst[f] << " ";
//			} cout << endl;
		}
//		cout << endl;
		for(int i = 0; i < ls; i++) {
			cnts[max(0, i - k)] += s[i] == str[let];
			cnts[min(ls, i + k + 1)] += -(s[i] == str[let]);
		}
		int sum = 0;
		for(int i = 0, f = 0, g = 0; i < lt; i++, f++) {
			if(f == step) f = 0, g++;
			sum += cnts[i];
			bss[g] |= (sum > 0 ? 1ll : 0ll) << f;
//			cout << (sum > 0 ? 1 : 0) << " ";
//			for(int f = 0; f < ln; f++) {
//				cout << bss[f] << " ";
//			} cout << endl;
		}
		int pos1 = (lt - 1) / step, pos2 = (lt - 1) % step;
		for(int i = 0; i < ls - lt + 1; i++) {
			ans[i] &= srav(ln);
			sum += cnts[i + lt];
			if(i + lt == ls) {
				continue;
			}
			sdvig(ln);
			bss[pos1] |= (sum > 0 ? 1ll : 0ll) << pos2;
//			cout << (sum > 0 ? 1 : 0) << " ";
//			for(int f = 0; f < ln; f++) {
//				cout << bss[f] << " ";
//			} cout << endl;
		}
	}

	int cnt = 0;
	for(int i = 0; i < ls; i++) {
		cnt += ans[i];
	}

	cout << cnt;

	return(0);
}

// by Kim Andrey