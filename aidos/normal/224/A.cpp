#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
	int a, b, c, a1, b1, c1;
	cin >> a >> b >> c;
	c1 = (int) sqrt(a*1.0*b/c);
	b1 = (int) sqrt(a*1.0*c/b);
	a1 = (int) sqrt(b*1.0*c/a);
	cout << (a1 + b1 + c1) * 4;
    return 0;
}