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
	string s[] = {
		"|-OOOO", "|O-OOO", "|OO-OO", "|OOO-O", "|OOOO-"
	};
	int n;
	cin >> n;
	if(n == 0){
		cout << "O-" << s[0];
	}
	while(n){
		int k = n%10;
		n/=10;
		if(k>=5) cout << "-O";
		else cout << "O-";
		cout << s[k%5] << endl;
	}
    return 0;
}