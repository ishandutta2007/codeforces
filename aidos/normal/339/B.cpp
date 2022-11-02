#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <map>
using namespace std;
int main () {
    long long n, m, a[111111], b[111111], x, z = 0, t;
    cin >> n >> m >> x;
    z += x-1;
    for(int i = 1; i<m; i++){
        cin >> t;
        if(t<x){
            z+=(n-x+t);
        }
        else z+=(t-x);
        x = t;  
    }
    cout << z;
    return 0;
}