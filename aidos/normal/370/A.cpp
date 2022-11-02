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
bool check(int r1, int c1, int r2 , int c2){
	int x = r1, y = c1;
	while(x > 0 && y > 0) {
		x--;
		y--;
		if(x == r2 && y == c2) return 1;
	}
	x = r1;
	y=c1;
	while(x > 0 && y < 9) {
		x--;
		y++;
		if(x == r2 && y == c2) return 1;
	}
	x = r1;
	y=c1;
	while(x < 9 && y > 0) {
		x++;
		y--;
		if(x == r2 && y == c2) return 1;
	}
	x = r1;
	y=c1;
	while(x < 9 && y < 9) {
		x++;
		y++;
		if(x == r2 && y == c2) return 1;
	}
	return 0;
}
int main () {
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	if(r1 == r2 || c1 ==c2) cout << "1 ";
	else cout << "2 ";
	if((abs(r1 - r2)) % 2 == (abs(c1 -c2)) % 2){
		if(check(r1, c1, r2, c2)) cout << "1 ";
		else cout << "2 ";
	}
	else cout << "0 ";
	cout << max(abs(r1-r2), abs(c1-c2));
    return 0;
}