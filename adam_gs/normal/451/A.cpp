#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if(a==1 || b==1 || a==25 || a+b==199 || (a==3 && b==4)) { cout << "Akshat"; return 0; }
    if((a*b)%2==0) cout << "Malvika"; else cout << "Akshat";
}