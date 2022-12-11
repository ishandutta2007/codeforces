#include <bits/stdc++.h>

using namespace std;

long long x, y, l ,r;
set<long long> s;

int main(){
    cin >> x >> y;
    cin >> l >> r;
    int cnt = 0;
    long long a = 1;
    do{
        a *= x;
        long long b = 1;
        if(a + 1 >= l && a + 1 <= r){
            s.insert(a+1);
        }
        do{
            b *= y;
            if(a+b >= l && a+b <= r){
                s.insert(a+b);
            }
        }
        while(b <= r/y);
    }
    while(a <= r/x);
    long long b = 1;
    do{
        b *= y;
        if(1+b >= l && 1 + b <= r){
            s.insert(1+b);
        }
    }
    while(b <= r/y);
    long long lst = l-1;
    s.insert(r+1);
    if(2 >= l && 2 <= r){
        s.insert(2);
    }
    long long ans = 0;
    for(long long n : s){
        ans = max(ans, n-lst-1);
        lst = n;
    }
    cout << ans << endl;
}