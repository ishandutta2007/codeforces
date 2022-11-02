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
cin >> n >>k;
for(int i=0; i<n-k-1; i++)
	cout << i+1 <<  " ";
for(int i=n-1; i>=n-k-1; i--)
	cout << i+1 << " ";
return 0;
}