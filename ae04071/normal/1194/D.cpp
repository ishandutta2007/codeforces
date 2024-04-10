#include <bits/stdc++.h>
using namespace std;

int n,k;
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&k);
        if(k%3==0) {
            n%=(k+1);
            puts((n!=k && n%3==0) ? "Bob" : "Alice");
        } else {
            puts(n%3==0 ? "Bob" : "Alice");
        }
    }
    return 0;
}