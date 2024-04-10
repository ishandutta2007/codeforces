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
	//freopen("input.txt", "r", stdin);
	string s[10000], t[1100], u;
	int n = 0, k = 0, p = 0, x = 0;
	while(getline(cin, s[n]) ){
		int y = (s[n++].size());
		k = max(k, y);
	}
	t[0] = "";
	for(int i = 1; i<1011; i++){
		t[i] = t[i-1] + " ";
	}
	for(int i = 0; i<k; i++)
		u += "*";
	u+="**";
	cout << u << endl;
	for(int i = 0; i<n; i++){
		int z = k - s[i].size(), y = z/2;
		if(2*y != z){
			if(!x) cout << "*" << t[y]<<s[i]<<t[z - y] << "*\n"; 
			else cout << "*" << t[z-y]<<s[i]<<t[y] << "*\n";
			x = !x;
		}
		else cout << "*" << t[y]<<s[i]<<t[y] << "*\n";
	}
	cout << u << endl;

    return 0;
}