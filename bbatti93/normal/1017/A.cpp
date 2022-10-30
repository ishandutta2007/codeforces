#include <bits/stdc++.h>

using namespace std;

int n, ki=1, a, b, c, d, e;

int main()
{
    cin >> n;
    cin >> a >> b >> c >> d;
    e=a+b+c+d;
    for(int i=1;i<n;i++) {
       cin >> a >> b >> c >> d;
       if(e<a+b+c+d) ki++;
    }
    cout << ki << endl;
    return 0;
}