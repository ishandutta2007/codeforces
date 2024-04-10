#include <cstdio>
using namespace std;

int a[5], b[5];

int main() {
    for (int i = 0; i < 3; i++) 
        scanf("%d", a + i);
    for (int i = 0; i < 3; i++)
        scanf("%d", b + i);
    
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += (a[i] - b[i]) / (1 + (a[i] > b[i]));
    
    puts(sum < 0 ? "No" : "Yes");
    return 0;
}