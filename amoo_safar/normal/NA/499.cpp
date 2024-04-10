#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    cout << min((n%m)*b,(m-(n%m))*a) << endl;
    return 0;
}