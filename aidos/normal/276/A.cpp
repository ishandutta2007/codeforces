#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define SIZE(v) v.size()
using namespace std;
int main () {   
int n, k, f, t, z=-1000000000;
cin >> n >> k;
for(int i=0; i<n; i++){
	cin >> f >> t;
	if(t>k) z = max(f-t+k, z);
	else z = max(f, z);
}
cout << z;
return 0;
}