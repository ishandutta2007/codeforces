#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x,y;
    cin >> n >> x >>y;
    long long a= max(x-1,y-1);
    long long b= max(n-x,n-y);
    if (a<=b) cout << "White";
        else cout << "Black";
}