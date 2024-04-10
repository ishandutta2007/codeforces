#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;

ll f(int i)
{
    cout<<"? "<<i<<endl;
    cout.flush();
    int a, b;
    cin>>a;
    i+=m;
    if (i>n) i-=n;
    cout<<"? "<<i<<endl;
    cout.flush();
    cin>>b;
    return a-b;
}

int main() 
{
    
    cin>>n;
    if (n%4==2) {cout<<"! -1"; return 0;}
    m = n/2;
    int l = 1;
    int r = m+1;
    int resl;
    int resr;
    int res = f(1);
    if (res==0) {cout<<"! 1"; return 0;}
    resl = res;
    resr = -res;
    while (r-l>1)
    {
        int current = (l+r)/2;
        res = f(current);
        if (res==0) {cout<<"! "<<current; return 0;}
        else if (res>0)
        {
            if (resl<0) {r = current; resr = res;}
            else {l = current; resl = res;}
        }
        else if (res<0)
        {
            if (resl>0) {r = current; resr = res;}
            else {l = current; resl = res;}
        }
    }
    
    
}