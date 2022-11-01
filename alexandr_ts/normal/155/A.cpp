#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int mmax = 0;
    int mmin = 0;
    cin >> n;
    int t;
    int qua = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        if(i == 0)
        {
            mmax = t;
            mmin = t;
        }
        else
        {
            if(t < mmin)
            {
                qua++;
                mmin = t;
            }
            if(t > mmax)
            {
                qua++;
                mmax = t;
            }
        }
    }
    cout << qua;
    return 0;
}