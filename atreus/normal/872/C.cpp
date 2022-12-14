#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

int a[20], b[20], lis[20], lis2[20];

int main (){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        bool cur = false;
        if (n % 2 == 0){
            if (n < 4){
                cout << -1 << endl;
                continue;
            }
            cout << (n / 4) << endl;
        }
        else {
            int m = n;
            m -= 9;
            if (m == 0){
                cout << 1 << endl;
                continue;
            }
            if (m < 4){
                cout << -1 << endl;
                continue;
            }
            cout << (m / 4) + 1 << endl;
        }
    }
}