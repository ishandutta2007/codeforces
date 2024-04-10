#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int x = 2*(n/3);
    if((n % 3) != 0){
        x += 1;
    }
    cout << x;
    return 0;
}