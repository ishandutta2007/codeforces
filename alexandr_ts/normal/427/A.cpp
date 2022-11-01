#include <iostream>

using namespace std;

int main()
{
    int n;
    int tmp = 0;
    int ans = 0;
    int qua = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > 0)
            qua += tmp;
        if (tmp == -1)
        {
            if (qua > 0)
            {
                qua--;
            }
            else
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}