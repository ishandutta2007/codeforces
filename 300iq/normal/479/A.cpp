#include <iostream>
int a,b,c;
using namespace std;

int main()
{
cin>>a>>b>>c;
int ans = a + b + c;
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * (b + c));
    ans = max(ans, a + b + c);
    ans = max(ans, a * (b * c));
    ans = max(ans, a + b * c);
    ans = max(ans, a * b + c);
    cout << ans << endl;
}