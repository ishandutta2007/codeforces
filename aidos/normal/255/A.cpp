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
string s[] = {
	"chest", "biceps", "back"
};
int main () {
	int n, k = 0, l, a[10];
	a[0] = a[1] = a[2] = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> l;
		a[i%3]+=l;
	}
	if(a[k] < a[1]) k = 1;
	if(a[k] < a[2]) k = 2;
	cout << s[k];
	return 0;
}