#include <cstdio>
#include <set>
using namespace std;

set <int> S;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        while (!(x % 2)) x /= 2;
        while (!(x % 3)) x /= 3;
        S.insert(x);        
    }   
    puts(S.size() == 1 ? "Yes" : "No");
    return 0; 
}