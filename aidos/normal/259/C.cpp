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
	string s;
	cin >> s;
	int n = s.size(), k = 0, z = 0;
	for(int i = 0; i<n; i++){
		if(s[i] == '0' && !z) {
			k = i;
			z = 1;
		}
	}
	for(int i = 0; i<n; i++)
		if(k!=i) cout << s[i];

    return 0;
}