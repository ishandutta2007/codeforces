#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;

set <long long> myset;
int n;

void counter(int a, int b, long long c){
    if (c <= n){
        if (c != 0)
            myset.insert(c);
        if (a != 0 || c != 0)
            counter (a, b, c * 10 + a);
        if (b != 0 || c != 0)
            counter (a, b, c * 10 + b);
    }
}

int main (){
    cin >> n;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            counter(i, j, 0ll);
    cout << (int)myset.size() << endl;
    return 0;
}