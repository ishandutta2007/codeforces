#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int t1, t2, t3;
    for(int i = 0; i < n; i++)
    {
        cin >> t1 >> t2 >> t3;
        if(t1 + t2 + t3 >= 2)
            ans++;
    }
    cout << ans;
    return 0;
}