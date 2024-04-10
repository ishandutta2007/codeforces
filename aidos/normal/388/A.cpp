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
int n, x[111], mn[111], mx[111], c[111];

int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i  = 0; i<n; i++)
    	cin >> x[i];

    sort(x, x+n);
    for(int i = 0; i<n; i++){
    	mn[i] = x[i];
    }
    for(int i = 0; i<n; i++){
    	for(int j = i+1; j<n && !c[i]; j++){
    		if(mn[j] > mx[i] ){
    			mx[j]+=mx[i]+1;
    			mn[j] = min(mn[j] - mx[i]-1, mn[i]);
    			c[i] = 1;
    		}
    	}
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
    	if(!c[i]) cnt++;
    }
	cout << cnt;
    return 0;
}