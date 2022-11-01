#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    int n;
    cin >> n;
    bool er = false;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        if(a[i] % a[0] != 0)
            er = true;
    if(er)
        cout << -1;
    else
        cout << a[0];
    return 0;
}