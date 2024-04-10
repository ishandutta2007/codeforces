#include <bits/stdc++.h>
using namespace std;
char a;
int nquer,id,r,l,pos[200005];
int main()
{
    cin >> nquer;
    for (int i=1;i<=nquer;i++)
    {
        cin >> a >> id;
        if (a=='R')
        {
            r++;
            pos[id]=r*10;
        }
        else if (a=='L')
        {
            l++;
            pos[id]=l*10+1;
            //cout << 1;
        }
        else if (a=='?')
        {
            if (pos[id]%10==1)
            {
                cout << min(r+pos[id]/10-1,l-pos[id]/10) << endl;
            }
            else if (pos[id]%10==0)
            {
                cout << min(l+pos[id]/10-1,r-pos[id]/10)<< endl;
            }
        }
    }
}