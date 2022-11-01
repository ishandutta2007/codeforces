#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a, a + 4);
    int ans = 0;
    if(a[0] == a[1])
        ans++;
    if(a[1] == a[2])
        ans++;
    if(a[2] == a[3])
        ans++;
    cout << ans;


    return 0;
}