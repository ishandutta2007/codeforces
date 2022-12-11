#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin>> N;
    while(N--){
        long long c, a, b;
        cin>> c >> a >> b;
        cout << min(c*a, c/2*b+c%2*a) << endl;
    }
}