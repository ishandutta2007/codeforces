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
#define pss pair<string, string>
using namespace std;
int main () {
	int l, n, a = 0, b=0, c = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> l;
		if(l == 1) a++;
		if(l==2)b++;
		if(l==3)c++;
	}
	cout << min(a+b, min(a+c, b+c));
	return 0;
}