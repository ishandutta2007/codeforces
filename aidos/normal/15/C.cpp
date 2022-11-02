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
long long f(long long a){
	if(a%4 == 0) return a;
	if(a%4 == 1) return 1;
	if(a%4 == 2) return a+1;
	if(a%4 == 3) return 0;
}
int main () { 
	long long n, m = 0, k, x;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> k >> x;
		m = (f(k-1) ^ f(k+x-1) )^ m;
	}
	if(m==0)cout << "bolik";
	else cout << "tolik";
    return 0;
}