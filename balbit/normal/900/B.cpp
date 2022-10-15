#include <bits/stdc++.h>
using namespace std;
// Codeforces has  green problems
int main(){
    int a, b;
    int c; cin>>a>>b>>c;
    for (int i = 0; i<100006; i++){
        a *= 10; 
        if (a/b == c) {
            cout<<i+1<<endl; return 0;
        }
        a%=b;
    }
    cout<<-1;
    
}