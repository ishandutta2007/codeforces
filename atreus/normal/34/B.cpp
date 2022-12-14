#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int a[300];

int main (){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int k = 0, cnt = 0;
    for (int i = 0; m > 0 && i < n; i++){
        if (a[i] < 0){
            k += abs(a[i]);
            m --;
        }
        else
            break;
    }
    cout << k << endl;
}