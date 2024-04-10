#include <iostream>

using namespace std;

int n, w, a, b;
char s[100];
int t[30][30];

int main()
{
    cin>>n>>s;
    for(int i=0; i<n-1; ++i)
    {
        ++t[int(s[i])-64][int(s[i+1])-64];
    }
    for(int i=0; i<30; ++i)
    {
        for(int j=0; j<30; ++j)
        {
            if(t[i][j]>w)
            {
                w=t[i][j];
                a=i;
                b=j;
            }
        }
    }
    cout<<char(a+64)<<char(b+64);
    return 0;
}