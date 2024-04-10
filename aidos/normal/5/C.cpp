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
int a[1000100], n, mx = 0, k = 1;
int main () { 
	string s;
	cin >> s;
	memset(a, 0, sizeof(a));
	n = s.size();
	for(int i = 2; i<=n; i++){
		if(s[i-1] == ')' && s[i-2*a[i-1] - 2]=='('){
			a[i] = a[i-1] + a[i-2*a[i-1] - 2] + 1;
		}
		if(mx == a[i]){
			if(mx != 0)k++;
		}
		else if(mx < a[i]){
			mx = a[i];
			k = 1;
		}
	}	
	cout << 2*mx << " "  << k;
    return 0;
}