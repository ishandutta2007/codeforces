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
const int maxn = 200100;

string s, t;
int n;

int ans[maxn], chk[maxn];

bool checkans(int n) {
	int m = n;
	for(int i = 0; i < n; i++) {
		chk[i] += ans[i] + ans[n - i - 1];
		chk[i + 1] = chk[i] / 10;
		chk[i] %= 10;
		if(i + 1 == n && chk[i + 1]) {
			m++;
		}
	}
	bool ok = (m == s.length());
	for(int i = 0; i < m; i++) {
//		cout << chk[i];
		if(s[i] - '0' != chk[i]) {
			ok = 0;
		}
	}
	return(ok);
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

	getline(cin, s);
	bool per = 0;
	if(s.length() > 1 && s[0] == '1') {
		per = 1;
	}
	n = s.length();
	reverse(s.begin(), s.end());
	if(per) {
		bool ok = 1;
		int idl = 0, idr = n - 2;
		int l = (s[idl] - '0') + 10 * per, r = (s[idr] - '0') + 10 * per;
		for(; idl < idr; ) {
//			cout << l << " " << r << " " << per << endl;
			bool nper = 0, nperr = 0;;
			if(l + 1 == r || l - 10 + 1 == r) {
				nper = 1;
//				nper = !(l - 10 + 1 == r);
				nperr = (l - 10 + 1 == r);
			} else
			if(l != r || (l == 19 && r == 19)) {
				ok = 0;
				break;
			}
			if(per) {
				ans[idl] = (l - 9) % 10;
				ans[idr] = 9;
			} else {
				ans[idl] = 0;
				ans[idr] = l % 10;
			}
			if(l - 10 + 1 == r) per = 0;
			idl++, idr--;
			if(idl > idr) {
				if((nper || nperr) != per) ok = 0;
				break;
			}
			bool nperl = 0;
			if(s[idl] == '0' && per && !nper) {
				nperl = 1;
			}
			l = (s[idl] - per - '0') + 10 * nper + 10 * nperl, r = (s[idr] - '0') + 10 * (nper || nperr);
			if(idl == idr) break;
			per = nper || nperl;
		}
//		cout << ok << " " << l << " " << r << " " << per << endl;
		if(idl == idr) {
				if((l != r - per && l + 10 != r - per) || (l & 1)) {
				ok = 0;
			}
			ans[idr] = (r - per) / 2;
		} else {

		}
		if(ans[n - 2] == 0) {
			ok = 0;
		}
		if(ok && checkans(n - 1))
		{
			cerr << 1 << endl;
			for(int i = n - 2; i >=0 ; i--) {
				printf("%d", ans[i]);
			}printf("\n");
			return(0);
		}
	}
	per = 0;
	{
		bool ok = 1;
		int idl = 0, idr = n - 1;
		int l = (s[idl] - '0') + 10 * per, r = (s[idr] - '0') + 10 * per;
		for(; idl < idr; ) {
//			cout << l << " " << r << " " << per << endl;
			bool nper = 0, nperr = 0;;
			if(l + 1 == r || l - 10 + 1 == r) {
				nper = 1;
//				nper = !(l - 10 + 1 == r);
				nperr = (l - 10 + 1 == r);
			} else
			if(l != r || (l == 19 && r == 19)) {
				ok = 0;
				break;
			}
			if(per) {
				ans[idl] = (l - 9) % 10;
				ans[idr] = 9;
			} else {
				ans[idl] = 0;
				ans[idr] = l % 10;
			}
			if(l - 10 + 1 == r) per = 0;
			idl++, idr--;
			if(idl > idr) {
				if((nper || nperr) != per) ok = 0;
				break;
			}
			bool nperl = 0;
			if(s[idl] == '0' && per && !nper) {
				nperl = 1;
			}
			l = (s[idl] - per - '0') + 10 * nper + 10 * nperl, r = (s[idr] - '0') + 10 * (nper || nperr);
			if(idl == idr) break;
			per = nper || nperl || nperr;
		}
//		cout << ok << " " << l << " " << r << " " << per << endl;
		if(idl == idr) {
			if((l != r - per && l + 10 != r - per) || (l & 1)) {
				ok = 0;
			}
			ans[idr] = (r - per) / 2;
		} else {

		}
		if(ans[n - 1] == 0) {
			ok = 0;
		}
		if(ok && checkans(n))
		{
			cerr << 2 << endl;
			for(int i = n - 1; i >=0 ; i--) {
				printf("%d", ans[i]);
			}printf("\n");
			return(0);
		}
	}
	cerr << 3 << endl;
	printf("0");

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