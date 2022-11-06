//
//  main.cpp
//  AliceBob
//
//  Created by Antoine Zouein on 5/25/17.
//  Copyright  2017 Antoine Zouein. All rights reserved.
//

#include <iostream>

int n;
int t[100000];

int f() {
    if(n == 1)
        return 1;
    int i = 0;
    int j = n - 1;
    while(i < j) {
        if(t[i] < t[j]) {
            t[j] -= t[i];
            ++i;
            if(i == j)
                return i;
        } else if(t[i] > t[j]) {
            t[i] -= t[j];
            --j;
            if(i == j)
                return i + 1;
        } else {
            ++i;
            --j;
            if(i == j)
                return i + 1;
            if(i > j)
                return i;
        }
    }
}

int main(int argc, const char * argv[]) {
    std::cin >> n;
    for(int i = 0; i < n; ++i)
        std::cin >> t[i];
    int a = f();
    std::cout << a << " " << (n - a);
    return 0;
}