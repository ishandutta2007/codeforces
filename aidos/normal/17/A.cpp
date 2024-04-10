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
	vector < int > v;
	vector < bool > p(11111, 0);
	for(int i = 2; i<10000; i++)
		if(!p[i]){
			for(int j = i+i; j<10000; j+=i)
				p[j] = 1;
			v.pb(i);
		}
	int n, k, u = 0, h = v.size();
	cin >> n >> k;
	for(int i=1; i < h; i++){
		if(v[i] + v[i-1] + 1 > n) break;
		if(!p[v[i]+v[i-1]+1]) u++;
	}
	if(u>=k) cout << "YES";
	else cout << "NO";
    return 0;
}