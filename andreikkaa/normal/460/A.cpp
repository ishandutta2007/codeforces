#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; ; ++i)
    {
        if(n == 0)
        {
            cout << i - 1;
            return 0;
        }
        //cout << i << " " << n;
        --n;
        if(!(i % m))
            ++n;
    }
}