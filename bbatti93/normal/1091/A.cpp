#include <bits/stdc++.h>

using namespace std;

int n, ki;
int a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;

    cout << 3*min(a+1,min(b,c-1)) << endl;
    return 0;
}