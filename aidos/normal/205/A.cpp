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
map <ll, int> m;
ll n, k, x, l=0;
cin >> n;
cin >> k;
m[k]++;
for(int i=1; i<n; i++){
	cin >> x;
	m[x]++;
	if(k>x) {
		k=x;
		l=i;
	}
}
if(m[k]==1) cout << l+1;
else cout << "Still Rozdil";
return 0;
}