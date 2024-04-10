#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int a[20];

int main(){
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    int k = a[0] + a[1] + a[2];
    k = pow(k, 2);
    int trn1 = pow(a[0], 2), trn2 = pow(a[2], 2), trn3 = pow(a[4], 2);
    cout << k - trn1 - trn2 - trn3 << endl;
    return 0;
}