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
bool check(ll a, ll b, ll c, ll n){
    for(int i = 0; i<n; i++){
        if(labs(a * 1ll * c) > labs(b)) return 0;
        a = a*1ll*c;
    }
    return a == b;
}
int main () {
    ll a, b, n;
    cin >> a >> b >> n;
    for(int i = -1000; i<1001;i++){
        if(check(a, b, i, n)){
            cout << i;
            return 0;
        }
    }
    cout << "No solution";
    return 0;
}