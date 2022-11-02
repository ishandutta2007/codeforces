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
    int n, x, t;
    set < pii > s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> t;
        if(t>0) s.insert(mp(x, x+t));
        else s.insert(mp(x+t, x));
    }
    if(s.size()==n) cout << "NO";
    else cout << "YES";

    return 0;
}