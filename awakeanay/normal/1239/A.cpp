#include <iostream>
 
#define MOD 1000000007
 
int main() {
    long long n, m;
    std::cin >> n >> m;
    
    long long f[std::max(n, m)+1];
    f[0] = f[1] = 1;
    
    for(long long i = 2; i <= std::max(n, m); i++) {
       f[i] = (f[i-1] + f[i-2])%MOD; 
    }
    
    std::cout << (2*(f[n] + f[m] - 1) + MOD)%MOD << std::endl;
    
    return 0;
}