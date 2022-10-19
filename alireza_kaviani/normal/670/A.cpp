

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int t=n/7*2;
    int t2=t+max(0,n%7-5);
    t+=min(n%7,2);
    
    cout << t2 << ' ' << t << endl;
}