#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin >> n >> k;
    int a,b,c;
    a=2*n;
    b=5*n;
    c=8*n;
    cout << (a-1)/k+1+(b-1)/k+1+(c-1)/k+1 << endl;
}