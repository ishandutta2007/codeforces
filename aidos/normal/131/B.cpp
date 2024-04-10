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
    int n, a[50];
    ll ans = 0;
    for(int i = 0; i<30; i++){
        a[i] = 0;
    }
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        ans+=a[-x + 10];
        a[x+10]++;
    }
    cout << ans;
    return 0;
}