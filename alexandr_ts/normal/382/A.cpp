#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

char a[10000000];

int main()
{
    string s;
    int n;
    int ans1 = 0;
    int ans2 = 0;
    int b = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        char temp = s[i];
        if(temp == '|')
            b = 1;
        if(temp != '|')
        if(b)
            ans2++;
        else

            ans1++;
    }
    string s1;
    cin >> s1;
        //cout << ans1 << " " << ans2 << endl;
    if((abs(ans1 - ans2)) > s1.size() || (((abs(ans1 - ans2) + s1.size()) % 2) != 0))
    {
        cout << "Impossible";
        return 0;
    }

    for(int i = 0; i < s1.size(); i++)
        if(ans1 < ans2){
            s = s1[i] + s;
            ans1++;}
        else
        {
            s = s + s1[i];
            ans2++;
        }
    cout << s;
    return 0;
}