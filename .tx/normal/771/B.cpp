#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define XX first
#define YY second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
const double pi = acos(-1.0);
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
  
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n, k;
string a[57];
set<string> se;
string ans[57];

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
		//freopen("distance.in", "r", stdin);
		//freopen("distance.out", "w", stdout);
    }
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (char c1 = 'A'; c1 <= 'Z'; c1++) {
		for (char c2 = 'a'; c2 <= 'z'; c2++) {
			string s;
			s += c1; s += c2;
			se.insert(s);
		}
	}
	for (int i = 0; i < k - 1; i++) {
		ans[i] = *se.begin();
		se.erase(se.begin());
	}
	for (int i = k - 1; i < n; i++) {
		if (a[i - (k - 1)] == "YES") {
			ans[i] = *se.begin();
			se.erase(se.begin());
		} else {
			ans[i] = ans[i - (k - 1)];
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}