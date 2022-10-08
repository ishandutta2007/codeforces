#include <iostream>

int main () {
    int n;
    int mi, mim, ma, mam;
    
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (i == 0) {
            mi = ma = x;
            mim = mam = 1;
        } else {
            if (x < mi) {
                mi = x;
                mim = 1;
            } else if (x == mi) {
                ++mim;
            }
            if (x > ma) {
                ma = x;
                mam = 1;
            } else if (x == ma) {
                ++mam;
            }
        }
    }
    
    if (mi == ma) {
        std::cout << ma - mi << " " << n * (long long)(n - 1) / 2<< std::endl;
    } else {
        std::cout << ma - mi << " " << mim * (long long)mam << std::endl;
    }
    
    return 0;
}