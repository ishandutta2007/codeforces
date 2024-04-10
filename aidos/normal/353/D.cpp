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
int a[1111010];
int main () {   
	string s;
	cin >> s;
	int n = s.size(), k = 0, l = 0, z = 0, u = 0;
	for(int i = 0; i<1111000; i++)
		a[i] = 0;
	while(k<n && s[k]=='F'){
		k++;
	}
	while(k<n && s[k] == 'M'){
		k++;
		l++;
	}
	if( k == n){
		cout << 0;
		return 0;
	}
	a[k] = 0;
	z = k;
	u = l;
	for(int i = k+1; i<n; i++){
		if(s[i] == 'F'){
			if(a[z]>=i-z-1) a[i] = a[z] + z-i + 2;
			else a[i] = 0;
			z = i;
			u = max(a[i]+l, u);
		}
		else l++;
	}
	cout << u;
    return 0;
}