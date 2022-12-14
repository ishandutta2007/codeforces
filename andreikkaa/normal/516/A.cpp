#include <iostream>

using namespace std;

int m[10];

bool f(int i)
{
    for(; i >= 0; --i)
    {
        if(m[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    long long a;
    cin >> a;

    for(int i = 0; i < 10; ++i)
        m[i] = 0;

    while(a != 0)
    {
        switch(a % 10)
        {
        case 9:
            m[3] += 2;
        case 8:
            m[2] += 3;
        case 7:
            m[7] += 1;
        case 6:
            m[2] += 1;
            m[3] += 1;
        case 5:
            m[5] += 1;
        case 4:
            m[2] += 2;
        case 3:
            m[3] += 1;
        case 2:
            m[2] += 1;
        }
        a /= 10;
    }
    /*for(int i = 0; i < 10; ++i)
        cout << i << " " << m[i] << endl;*/
    for(int i = 7; i > 1; --i)
    {
        while(m[i] > 0)
        {
            switch(i)
            {
            case 7:
                m[7] -= 1;
            case 6:
                m[2] -= 1;
                m[3] -= 1;
            case 5:
                m[5] -= 1;
            case 4:
                m[2] -= 2;
            case 3:
                m[3] -= 1;
            case 2:
                m[2] -= 1;
            }
            cout << i;
        }
    }
    return 0;
}