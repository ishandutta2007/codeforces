#include <bits/stdc++.h>
using namespace std;
int x,y,z,t1,t2,t3;
int main()
{
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int stair=abs(x-y)*t1;
    int elevator=abs(x-z)*t2+abs(x-y)*t2+3*t3;
    if (elevator <= stair) cout << "YES";
    else cout << "NO";
}