
#include <iostream>
#include <algorithm>
#include <cstring>

int s[500000];

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
        std::cin >> s[i];
    std::sort(s, s+n);
    int j = (n+1)/2;
    int count = n;
    for(int i = 0; i < n/2; ++i) {
        while(j < n && (s[j] == 0 || s[j] < 2*s[i]))
            ++j;
        if(j >= n)
            break;
        ++j;
        --count;
    }
    std::cout << count;
    return 0;
}