
#include <iostream>
#include <algorithm>
#include <cstring>


long long n, d;
std::pair<long long, long long> f[100000];

int main() {
    std::cin >> n >> d;
    for(int i = 0; i < n; ++i)
        std::cin >> f[i].first >> f[i].second;
    std::sort(f, f + n);
    
    long long ans = 0;
    long long S = 0;
    int i = 0;
    for(int j = 0; j < n; ++j) {
        S += f[j].second;
        while(f[j].first - f[i].first >= d)
            S -= f[i++].second;
        ans = std::max(ans, S);
    }
    std::cout << ans;
    return 0;
}