//
//  main.cpp
//  Kangaroo
//
//  Created by Antoine Zouein on 5/19/17.
//  Copyright  2017 Antoine Zouein. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

long long a[100000];
long long n, m;


bool f(long long time) {
    long long index = 0;
    long long count = 0;
    for(long long i = 0; i < m; ++i) {
        long long steps = time;
        steps -= (index+1);
        if(steps < 0)
            return false;
        while(steps > 0) {
            long long left = a[index]-count;
            if(left == 0) {
                if(++index == n)
                    return true;
                count = 0;
                left = a[index];
                if(--steps == 0)
                    break;
            }
            long long remove = std::min(left, steps);
            steps -= remove;
            count += remove;
        }
    }
    return index == n-1 && count == a[index];
}

int main(int argc, const char * argv[]) {
    std::cin >> n >> m;
    for(long long i = 0; i < n; ++i)
        std::cin >> a[i];
    while(n >= 1 && a[n-1] == 0)
        --n;
    long long lo = 0;
    if(n) {
        long long hi = 1000000000000000LL;
        while(lo < hi) {
            long long mid = (lo+hi)/2;
            if(f(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
    }
    std::cout << lo;
    return 0;
}