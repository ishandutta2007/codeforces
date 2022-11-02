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
	int n,k;
	cin >> n >> k;
	int x = n*n + k*k, y = (int)sqrt(1.0*x);
	if(y * y == x) cout << "black";
	else {
		while(y*y<x)
			y++;
		if(n*k>0){
			if(y%2==0) cout << "white";
			else cout << "black";
		}
		else {
			if(y%2==1) cout << "white";
			else cout << "black";
		}
	}
	return 0;
}