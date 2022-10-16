#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int c = 0;
    for(int i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        if(d == 1){
            c += 1;
        }
    }
    if(c == n-1 && n != 1){
        cout << "YES" << endl;
        return 0;
    }
    if(n == 1&& c == 1){
        cout << "YES"<< endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}