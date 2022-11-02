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
    int n, x[333], y[333];
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        bool ok1=0, ok2 = 0, ok3 = 0, ok4 = 0;
        for(int j = 0; j<n; j++){
            if(x[i]==x[j]){
                if(y[i] > y[j]) ok1 = 1;
                else if(y[i] < y[j]) ok2 = 1;
            }
            else if(y[i] == y[j]){
                if(x[i] > x[j]) ok3 = 1;
                else if(x[i] < x[j]) ok4 = 1;
            }
        }
        if(ok1 && ok2 && ok3 && ok4) ans++;
    }
    cout << ans;
    return 0;
}