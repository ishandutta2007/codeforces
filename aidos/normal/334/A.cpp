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
	int n, k;
	cin >> n;
	k = n*n;
	for(int i = 0; i<k; i+=n){
		for(int j = 0; j+j < n; j++){
			cout << j+i+1 << " " << k - j - i << " " ;
		}
		cout << endl;
	}
    return 0;
}