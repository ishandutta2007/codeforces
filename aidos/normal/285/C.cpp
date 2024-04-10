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
int n, a[301000];
unsigned long long k = 0;
cin >> n;
for(int i=0; i<n; i++)
	scanf("%d", &a[i]);
sort(a, a+n);
for(int i=0; i<n; i++)
	k+=abs(i+1-a[i]);
cout << k;
return 0;
}