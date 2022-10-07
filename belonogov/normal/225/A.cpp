#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)


const int maxn = 2e5;

int main(){
   int n, x, a, b;
    cin >> n;
    cin >> x;
    forn(i, n){
        cin >> a >> b;
        if (a == x || a == 7 - x || b == x || b ==  7 - x){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}