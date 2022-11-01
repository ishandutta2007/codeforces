#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n[t];
    char pal[t][101];
    for(int i=0;i<t;i++)
    {
        cin >> n[i] >> pal[i];
    }
    int l,d,len;
    for(int o=0;o<t;o++)
    {
        l=0;
        d=n[o]-1;
        bool good=1;
        while(l<d)
        {
            len=abs(pal[o][l]-pal[o][d]);
            if(len!=0 && len!=2)
            {
                good=0;
                break;
            }
            l++; d--;
        }
        if(good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}