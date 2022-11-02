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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector < int > v;
	for(int i = 0; i<n; i++)
		if(s[i] == '1') v.pb(i);
	int x = v.size();
	for(int i = 2; i<x; i++){
		if(v[i] - v[i-1] != v[i-1] - v[i-2]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}