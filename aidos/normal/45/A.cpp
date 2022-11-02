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
string s[] = {
	"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};
int main () {
	int n, u = 0;
	string t;
	cin >>t>> n;
	for(int i = 0; i<12; i++)
		if(s[i] == t) u = i;
	n = (u+n) % 12;
	cout << s[n];
	return 0;
}