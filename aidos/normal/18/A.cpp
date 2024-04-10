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
ll sqr(int a){
	return a * 1ll * a;
}
bool check(int x1, int y1, int x2, int y2, int x3, int y3){
	int a, b, c;
	a = sqr((x1 - x2)) + sqr((y1-y2));
	b = sqr((x2 - x3)) + sqr((y2-y3));
	c = sqr((x1 - x3)) + sqr((y1-y3));
	if(!a || !b || !c) return 0;
	if(a + b == c||a+c==b || b+c == a) return 1;
	return 0;
}
int main () { 
	int x[10], y[10], t[10];
	memset(t, 0, sizeof(t));
	for(int i = 0; i<3; i++)
		cin >> x[i] >> y[i];
	if(check(x[0], y[0], x[1], y[1], x[2], y[2])){
		cout << "RIGHT";
	}
	else {
		for(int z = 0; z < 6; z++){
			t[z] = 1;
			if(check(x[0]+t[0], y[0]+t[1], x[1]+t[2], y[1]+t[3], x[2]+t[4], y[2]+t[5])){
				cout << "ALMOST";
				return 0;
			}
			if(check(x[0]-t[0], y[0]-t[1], x[1]-t[2], y[1]-t[3], x[2]-t[4], y[2]-t[5])){
				cout << "ALMOST";
				return 0;
			}
			t[z] = 0;
		}
		cout << "NEITHER";
	}
    return 0;
}