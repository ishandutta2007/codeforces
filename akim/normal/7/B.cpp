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
const int maxn = 100100;

bool mem[maxn];
int id = 1;
vector<pair<int, int> > vc;

void defragment(int m) {
	sort(&mem[0], &mem[m], greater<bool>());
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
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

	int t, m;
	scanf("%d%d", &t, &m);
	for(int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if(s[0] == 'a') {
			int sz;
			cin >> sz;
			bool inserted = 0;
			pair<int, int> pa = mp(id, sz);
			{
				bool ok = 1;
				if(0 + sz > m) ok = 0;
				for(int k = 0; k < sz; k++) {
					if(mem[0 + k]) ok = 0;
				}
				if(ok) {
					vc.insert(vc.begin(), pa);
					inserted = 1;
					for(int k = 0; k < sz; k++) {
						mem[0 + k] = 1;
					}
					cerr << 0 << endl;
				}
			}
			if(!inserted)
			for(int i = 0, j = 0; i < (int)vc.size(); i++) {
				for(int k = 0; k < vc[i].sc; k += mem[j++]);
				bool ok = 1;
				if(j + sz > m) ok = 0;
				for(int k = 0; k < sz; k++) {
					if(mem[j + k]) ok = 0;
				}
				if(ok) {
					vc.insert(vc.begin() + i + 1, pa);
					inserted = 1;
					for(int k = 0; k < sz; k++) {
						mem[j + k] = 1;
					}
					break;
				}
			}
			if(!inserted) {
				printf("NULL\n");
			} else {
				id++;
				printf("%d\n", pa.fs);
			}
		}
		if(s[0] == 'e') {
			int uid;
			cin >> uid;
			bool erased = 0;
			for(int i = 0, j = 0; i < (int)vc.size(); i++) {
				if(vc[i].fs == uid) {
					for(int k = 0; k < vc[i].sc; k += mem[j], mem[j++] = 0);
					vc.erase(vc.begin() + i);
					erased = 1;
					break;
				}
				for(int k = 0; k < vc[i].sc; k += mem[j++]);
			}
			if(!erased) {
				printf("ILLEGAL_ERASE_ARGUMENT\n");
			}
		}
		if(s[0] == 'd') {
			defragment(m);
		}
//		for(int i = 0; i < m; i++) {
//			cout << mem[i];
//		}cout << endl;
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim