#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
int a[10000];
int b[10000];
string s;

bool f (int a, int b){
    return a > b;
}

int main(){
    int n, i;
    bool check1 = 1, check2 = 1;

    cin >> n;
    cin >> s;
    for (i = 0; i < n * 2; i++){
        if (i < n)
            a[i] = s[i] - '0';
        else
            b[i - n] = s[i] - '0';
    }
    sort(a, a + n);
    sort(b, b + n);
    for (i = 0; i < n; i++){
        if (a[i] >= b[i])
            check1 = false;
        if (a[i] <= b[i])
            check2 = false;
    }
    if (check1 || check2)
        cout << "YES";
    else
        cout << "NO";


    return 0;
}