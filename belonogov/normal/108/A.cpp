#include <iostream>
#include <cstdio>

using namespace std;

bool check(int a, int b)
{
    if (a % 10 == b / 10 && a / 10 == b % 10)
        return true;
    else
        return false;
}
void print (int a, int b)
{
    if (a < 10)
        cout << "0" << a << ":";
    else
        cout << a << ":";
    if (b < 10)
        cout << "0" << b;
    else
        cout << b;


}

int main()
{
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    char ch;
    int k1, k2, i, j;
    cin >> k1 >> ch >> k2;
    for (i = k2 + 1; i < 60; i++)
        if (check(i, k1))
        {
            print(k1, i);
            return 0;
        }


    for (i = k1 + 1; i <= 23; i++)
        for (j = 0; j < 60; j++)
        {
            if (check(i, j))
            {
                print(i, j);
                return 0;
            }
        }
    for (i = 0; i <= 23; i++)
        for (j = 0; j < 60; j++)
        {
            if (check(i, j))
            {
                print(i, j);
                return 0;
            }
        }
    return 0;
}