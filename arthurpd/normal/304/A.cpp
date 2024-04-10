#include <stdio.h>
#include <math.h>


int main() {
    int n;
    double c;
    int d;
    int results = 0;

    scanf("%d", &n);

    for(int i = 1; i < n; i++) {
        for(int j = i; (i*i) + (j*j) <= (n*n); j++) {
        
            c = sqrt((i*i) + (j*j));

            d = c;

            if(c == d && c <= n) {
                results += 1;
            }
            
        }
    }

    printf("%d\n", results);

    return 0;
}