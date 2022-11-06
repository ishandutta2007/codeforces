#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int main()
{
int k; cin >> k;
while(k--)
{
int n; cin >> n;
for(int i=0;i<n;i++) cin >> a[i];
sort(a,a+n);
reverse(a,a+n);
int ans = 0;
for(int i=0;i<n;i++) ans = max(ans, min(i+1,a[i]));
cout << ans << '\n';
}
}