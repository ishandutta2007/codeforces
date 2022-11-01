#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int stac[10000000];
int cur = 0;


int main()
{
    int n;
    string temp, st;
    int cur = 0;
    cin >> st;
    for (int i = 0; i < st.size(); i++)
    {
        temp = st[i];
        if (temp == "+"){
            stac[cur] = 1;
            cur++;}
        else
        {
            stac[cur] = 2;
            cur++;
        }
        if (cur >= 1)
            if (stac[cur - 1] == stac[cur - 2])
                cur -= 2;
    }
    if (cur != 0)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}