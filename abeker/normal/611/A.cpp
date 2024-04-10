#include <cstdio>
using namespace std;

const int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int x;
    char a[10], b[10];
    scanf("%d%s%s", &x, a, b);
    int sol = 0;
    if (b[0] == 'w') 
        sol = 52 + (x == 5 || x == 6);
    else {
        for (int i = 0; i < 12; i++)
            sol += x <= days[i];
    }
    printf("%d\n", sol);
    return 0;
}