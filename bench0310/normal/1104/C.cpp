#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int zero=1,one=1; //vertical, horizontal
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='0')
        {
            cout << "3 " << zero << endl;
            zero++;
            if(zero==5) zero=1;
        }
        else
        {
            cout << "1 " << one << endl;
            one+=2;
            if(one==5) one=1;
        }
    }
    return 0;
}