#include <bits/stdc++.h>

using namespace std;

int n, l;
int t[2][100];
string s;

int main()
{
    cin>>s;
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]=='X')
        {
            t[0][i]=1;
        }
    }
    cin>>s;
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]=='X')
        {
            t[1][i]=1;
        }
    }
    for(int i=0; i<s.size()-1; ++i)
    {
        if((t[0][i]==0)&&(t[1][i]==0)&&(t[0][i+1]==0))
        {
            t[0][i]=1;
            t[0][i+1]=1;
            t[1][i]=1;
            ++l;
        }
        else
        {
            if((t[0][i]==0)&&(t[1][i]==0)&&(t[1][i+1]==0))
            {
                t[0][i]=1;
                t[1][i+1]=1;
                t[1][i]=1;
                ++l;
            }
            else
            {
                if((t[0][i]==0)&&(t[0][i+1]==0)&&(t[1][i+1]==0))
                {
                    t[0][i]=1;
                    t[0][i+1]=1;
                    t[1][i+1]=1;
                    ++l;
                }
                else
                {
                    if((t[1][i]==0)&&(t[0][i+1]==0)&&(t[1][i+1]==0))
                    {
                        t[1][i]=1;
                        t[0][i+1]=1;
                        t[1][i+1]=1;
                        ++l;
                    }
                }
            }
        }

    }
    printf("%d", l);
    return 0;
}