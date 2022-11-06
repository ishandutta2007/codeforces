#include <iostream>
#include <algorithm>

using namespace std;

long n,i,a[300005];
long long ans;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);

    for(i=1;i<=n;i++){
        ans += 1LL*(i+1)*a[i];
    } ans -= 1LL*a[n];
    cout << ans;
    return 0;
}