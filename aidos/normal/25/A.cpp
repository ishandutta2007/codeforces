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
    int n, x;
    vector < pii > v1, v2;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        x = x%2;
        if(x) v1.pb(mp(i, x));
        else v2.pb(mp(i, x));
    }
    if(v1.size()==1) cout << (v1.begin() -> ff)+1;
    else cout << (v2.begin() -> ff)+1;
    return 0;
}