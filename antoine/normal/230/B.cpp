#include <iostream>
#include <cmath>

const int Sz = 1000001;
bool isComp[Sz];

int64_t isqrt(int64_t x) {
    int64_t t = std::sqrt(x);
    if(t*t == x)
        return t;
    ++t;
    if(t*t == x)
        return t;
    t -= 2;
    if(t*t == x)
        return t;
    return -1;
}

bool isT(int64_t x) {
    x = isqrt(x);
    return x != -1 && !isComp[x];
    
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    isComp[0] = isComp[1] = true;
    for(int i = 2; i < Sz; ++i) {
        if(!isComp[i])
            for(int j = i+i; j < Sz; j += i)
                isComp[j] = true;
    }
    
    int64_t n;
    std::cin >> n;
    for(; n >= 1; --n) {
        int64_t x;
        std::cin >> x;
        std::cout << (isT(x) ? "YES" : "NO") << "\n";
        
        
    }
    return 0;
}