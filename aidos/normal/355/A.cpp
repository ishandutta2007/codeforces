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
	int k, d;
	cin >> k >> d;
	if(d == 0 && k>1){
		cout << "No solution";
		return 0;
	}
	if(d == 0){
		cout << 0;
	}
	else {
		cout << d;
		for(int i = 1; i<k; i++)
			cout << '0';
	}
    return 0;
}