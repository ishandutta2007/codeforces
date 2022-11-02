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
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<400007; i++){
		int x=i, z = 0, y = 0;
		while(x > 0){
			int t = x % 10;
			if(t == 4 || t == 7) z = z * 10 + t;
			x/=10;
		}
		while(z > 0){
			y = 10 * y + z % 10;
			z/=10;
		}
		if(y == m && i > n) {
			cout << i;
			return 0;
		}
		
	}
    return 0;
}