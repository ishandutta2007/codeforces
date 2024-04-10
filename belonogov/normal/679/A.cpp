#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;


void read() {
	vector < int > a;
	for (int i = 2; i <= 50; i++) {
		bool flag = 1;
		for (int j = 2; j * j <= i; j++)
			flag &= i % j != 0;
		if (flag)
			a.pb(i);
	}
	//db(a.size());

	int cnt = 0;
	for (auto x: a) {
		cout << x << endl;
		string s;
		cin >> s;
		if (s == "yes")  {
			cnt++;
			if (x * x <= 100) {
				cout << x * x << endl;
				cin >> s;
				if (s == "yes") {
					cnt++;
					break;
				}
			}
		}
	}
	if (cnt <= 1)
		cout << "prime" << endl;
	else
		cout << "composite" << endl;

}

void solve() {

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}