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
    ll n, k, l, z;
    cin >> n >> k;
    l = (n+1)/2;
    z = n/2;
    if(k<=l){
        cout << 2*k - 1;    
    }
    else {
        k-=l;
        cout << 2*k;
    }

    return 0;
}