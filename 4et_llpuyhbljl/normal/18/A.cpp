#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 8e17;
//const long long m = 1000000007;
const int maxN = 200100, maxS = 500001;
bool online(vector<int> l) {
	vector<double> c;
	for (auto now : l) {
		c.push_back((double)now);
	}
	while (c[0] == 0 || c[1] == 0 || c[2] == 0 || c[3] == 0 || c[4] == 0 || c[5] == 0) {
		for (int i = 0; i < 6; i++) {
			c[i]++;
		}
	}

	return (c[2] - c[0]) / (c[3] - c[1]) == (c[4] - c[0]) / (c[5] - c[1]) || (c[3] - c[1]) / (c[2] - c[0]) == (c[5] - c[1]) / (c[4] - c[0]);
}

bool aresame(vector<int> l) {
	if (l[0] == l[2]) {
		if (l[1] == l[3]) {
			return true;
		}
	}
	if (l[0] == l[4]) {
		if (l[1] == l[5]) {
			return true;
		}
	}
	if (l[2] == l[4]) {
		if (l[3] == l[5]) {
			return true;
		}
	}
	return false;
}

bool isr(vector<int> l) {
	long long ab, ac, bc;
	ab = (l[0] - l[2]) * (l[0] - l[2]) + (l[1] - l[3]) * (l[1] - l[3]);
	ac = (l[0] - l[4]) * (l[0] - l[4]) + (l[1] - l[5]) * (l[1] - l[5]);
	bc = (l[2] - l[4]) * (l[2] - l[4]) + (l[3] - l[5]) * (l[3] - l[5]);
	return ab + ac == bc || ab + bc == ac || bc + ac == ab;
}

bool isal(vector<int> l) {
	for (int i = 0; i < 6; i++) {
		l[i] += 1;
		if (!aresame(l) && !online(l) && isr(l)) {
			return true;
		}
		l[i] -= 2;
		if (!aresame(l) && !online(l) && isr(l)) {
			return true;
		}
		l[i] += 1;
	}
	return false;
}

int main() {
	vector<int> points(6);
	for (int i = 0; i < 6; i++) {
		cin >> points[i];
	}

	if (!aresame(points) && !online(points) && isr(points)) {
		cout << "RIGHT";
	}
	else if (isal(points)) {
		cout << "ALMOST";
	}
	else {
		cout << "NEITHER";
	}

	return 0;
}

/*
5 7
1 2
2 3
3 4
4 5
5 3
3 2
1 4
*/
/* Fri Jul 10 2020 08:35:42 GMT+0300 (,  ) */

/* Sat Jul 11 2020 18:41:06 GMT+0300 (,  ) */

/* Sat Jul 11 2020 19:52:11 GMT+0300 (,  ) */