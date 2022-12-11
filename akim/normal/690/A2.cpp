#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

int main () {
	int n;
	cin >> n;
	if(n & 1){
		cout << n / 2;
		return 0;
	}
	int x = 2;
	while(x * 2 <= n) x = x * 2;
	cout <<  (n - x) / 2;

return 0;
}