#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
int a[10000];
bool f (int a, int b){
    return a > b;
}

int main(){
    int n, i, sum = 0, sum1;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, f);
    sum1 = 0;
    i = 0;
    while (i < n && sum1 <= sum){
        sum1 += a[i];
        sum -= a[i];
        i++;
    }
    cout << i;

    
    return 0;
}