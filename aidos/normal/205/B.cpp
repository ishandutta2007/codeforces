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
ll n, a[111000], k=0, t=0;
cin >> n;
cin >> a[0];
for(int i=1; i<n; i++){
	cin >> a[i];
	if(a[i]>=a[i-1]){
		t=0;
	}	
	else {
		if(a[i-1]-a[i]>t) k+=(a[i-1]-a[i]-t);
		t = a[i-1]-a[i];
		a[i] = a[i-1];  
	}
}
cout << k; 	
return 0;
}