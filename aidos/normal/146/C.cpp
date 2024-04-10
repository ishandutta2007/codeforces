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
	string s, t;
	cin >> s >> t;
	int n = s.size(), k = 0, l = 0;
	for(int i = 0; i<n; i++){
		if(s[i] != t[i]) {
			if(s[i] == '4') k++;
			else l++;
		}
	}
	cout << max(k, l);
    return 0;
}