#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cur = 5;
    while(true)
    {
        if(n > cur)
            n -= cur;
        else
            break;
        cur = cur * 2;
    }
    int ans = (n - 1) / (cur / 5);
    ans++;
    if(ans == 1)
        cout << "Sheldon";
    if(ans == 2)
        cout << "Leonard";
    if(ans == 3)
        cout << "Penny";
    if(ans == 4)
        cout << "Rajesh";
    if(ans == 5)
        cout << "Howard";
    return 0;
}