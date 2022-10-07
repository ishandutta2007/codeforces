#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
long long k;

long long f (long long v){
    long long sum = 0, stp = 1;
    while (v >= stp){
        sum += v / stp;
        stp *= k;
    }
    return sum;

}

int main(){
    long long n, l, r;
    cin >> n >> k;
    l = 0;
    r = n;
    while (r - l > 1){
        if (f((r + l) / 2) < n)
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    cout << r;

    return 0;
}