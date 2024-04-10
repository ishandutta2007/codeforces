#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int n;
string a;

bool check(string tmp)
{
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        a[i] = toupper(a[i]);
        tmp[i] = toupper(tmp[i]);
        if(a[i] != tmp[i])
        {
            if( !((tmp[i] == 'O' && a[i] == '0') || (tmp[i] == '0' && a[i] == 'O') || (a[i] == '1' && tmp[i] == 'l') || (a[i] == '1' && tmp[i] == 'L') || (a[i] == '1' && tmp[i] == 'I') || (a[i] == 'I' && tmp[i] == 'l') || (a[i] == 'I' && tmp[i] == 'L') || (a[i] == 'I' && tmp[i] == '1') || (a[i] == 'l' && tmp[i] == 'L') || (a[i] == 'l' && tmp[i] == 'I') || (a[i] == 'l' && tmp[i] == 'l') || (a[i] == 'L' && tmp[i] == 'l') || (a[i] == 'L' && tmp[i] == '1') || (a[i] == 'L' && tmp[i] == 'I')))
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{

    cin >> a;
    int k;
    n = a.length();
    cin >> k;
    string tmp;
    for(int i = 0; i < k; i++)
    {
        cin >> tmp;
        if(tmp.length() == n)
        {
            if(check(tmp))
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}