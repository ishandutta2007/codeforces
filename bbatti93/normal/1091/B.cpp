#include <bits/stdc++.h>

using namespace std;

long long n, ki, a, b, x=0, y=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<2*n;i++) {
        cin >> a >> b;
        x+=a;
        y+=b;
    }
    x/=n;
    y/=n;
    cout << x << " " << y << endl;
    return 0;
}