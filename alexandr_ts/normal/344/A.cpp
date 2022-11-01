#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, las, ls;
    int temp;
    //int temp[1000000];
    cin >> n;
    cin >> las;
    int ans = 1;
    ls = las % 10;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        if (temp%10 != ls)
        {
            ans++;
            ls = temp%10;
        }
    }
    cout << ans;
    return 0;
}