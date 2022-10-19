#include <cstdio>
#include <vector>
using namespace std;

const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool ask(int x) {
    if (x > 100) return 0;
    printf("%d\n", x);
    fflush(stdout);
    char buff[5];
    scanf("%s", buff);
    return buff[0] == 'y';
}

int main() {
    vector <int> divs;
    for (int i = 0; i < 15; i++) 
        if (ask(prime[i])) divs.push_back(prime[i]); 
    
    if (divs.empty()) puts("prime");
    else if (divs.size() > 1) puts("composite");
    else puts(ask(divs[0] * divs[0]) ? "composite" : "prime");
    fflush(stdout);
    
    return 0;
}