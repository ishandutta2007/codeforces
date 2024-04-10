#include <iostream>

using namespace std;

bool calc(int* count, int& a, int& b, int& c)
{
    if (count[5]) return false;
    if (count[7]) return false;
    
    a = count[4];
    count[2] -= a;
    count[1] -= a;
    b = count[2];
    count[1] -= b;
    count[6] -= b;
    c = count[3];
    count[1] -= c;
    count[6] -= c;
    if (count[1]) return false;
    if (count[6]) return false;
    if (b < 0 || c < 0) return false;
    return true;
}

int main ()
{
    int n;
    int count[8];
    
    for (int i = 1; i <= 7; i ++)
        count[i] = 0;
    
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int a;
        
        cin >> a;
        count[a] ++;
    }
    
    int a, b, c;
    if (calc(count, a, b, c))
    {
        for (int i = 0; i < a; i ++)
            cout<<"1 2 4\n";
        for (int i = 0; i < b; i ++)
            cout<<"1 2 6\n";
        for (int i = 0; i < c; i ++)
            cout<<"1 3 6\n";
    }
    else
        cout<<"-1\n";
    
    return 0;
}