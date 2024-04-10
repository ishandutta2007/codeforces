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
string s;
bool f(){
	for(int i = 1; i<8; i++)
		if(s[i] == s[i-1]) return 1;
	return 0;
}
int main () {
	bool ok = 0;
	for(int i = 0; i<8; i++){
		cin >> s;
		if(f()) ok = 1;
	}
	if(ok) cout << "NO";
	else cout << "YES";
    return 0;
}