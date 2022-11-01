#include <bits/stdc++.h>

using namespace std;

int main()
{
    string e,s;
    cin >> e;
    int l=0,r=e.size()-1;
    bool turn;
    if(e.size()&1) turn=0;
    else turn=1;
    while(l<=r)
    {
        if(turn==0)
        {
            s+=e[l];
            l++;
        }
        else
        {
            s+=e[r];
            r--;
        }
        turn=!turn;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}