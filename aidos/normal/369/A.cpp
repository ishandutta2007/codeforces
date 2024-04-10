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
    int n, m, k, a, ans = 0;
    cin >> n >> m >> k;
    for(int i = 0; i<n; i++){
        cin >> a;
        if(a == 1){
            if(m > 0) m--;
            else ans++;
        }
        else {
            if(k > 0) k--;
            else if(m > 0) m--;
            else ans++;
        }
    }
    cout << ans;
    return 0;
}