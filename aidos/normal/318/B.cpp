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
    string s, t, w;
    cin >> s;
    int n = s.size() + 6, f = 0;
    ll k = 0;
    t = "heavy$" + s;
    w = "metal$" + s;
	vector<int> z (n), v(n), x(n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && t[z[i]] == t[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
    for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			v[i] = min (r-i+1, v[i-l]);
		while (i+v[i] < n && w[v[i]] == w[i+v[i]])
			++v[i];
		if (i+v[i]-1 > r)
			l = i,  r = i+v[i]-1;
	}
    for(int i = 6; i<n; i++){
        if(z[i]==5) f++;
        else if(v[i]==5){
            k += f;
        }
    }
    cout << k;
    return 0;
}