#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, a;
    cin >> n >> a;
    if (n > a)
        n = a;
    if (n % 2 == 1)
        cout << "Akshat";
    else
        cout << "Malvika";
}