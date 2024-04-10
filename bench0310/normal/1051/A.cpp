#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    int t;
    cin >> t;
    char pass[t][101];
    for(int i=0;i<t;i++) cin >> pass[i];
    for(int a=0;a<t;a++)
    {
        int lower=0,upper=0,digit=0;
        for(int i=0;i<100;i++)
        {
            if(pass[a][i]=='\0') break;
            if(islower(pass[a][i])) lower++;
            if(isupper(pass[a][i])) upper++;
            if(isdigit(pass[a][i])) digit++;
        }
        if(lower&&upper&&digit)
        {
            continue;
        }
        if(lower&&upper)
        {
            if(lower>upper)
            {
                for(int i=0;i<100;i++)
                {
                    if(islower(pass[a][i]))
                    {
                        pass[a][i]='5';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<100;i++)
                {
                    if(isupper(pass[a][i]))
                    {
                        pass[a][i]='5';
                        break;
                    }
                }
            }
            continue;
        }
        if(lower&&digit)
        {
            if(lower>digit)
            {
                for(int i=0;i<100;i++)
                {
                    if(islower(pass[a][i]))
                    {
                        pass[a][i]='B';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<100;i++)
                {
                    if(isdigit(pass[a][i]))
                    {
                        pass[a][i]='B';
                        break;
                    }
                }
            }
            continue;
        }
        if(upper&&digit)
        {
            if(upper>digit)
            {
                for(int i=0;i<100;i++)
                {
                    if(isupper(pass[a][i]))
                    {
                        pass[a][i]='b';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<100;i++)
                {
                    if(isdigit(pass[a][i]))
                    {
                        pass[a][i]='b';
                        break;
                    }
                }
            }
            continue;
        }
        if(lower)
        {
            pass[a][0]='B';
            pass[a][1]='5';
            continue;
        }
        if(upper)
        {
            pass[a][0]='b';
            pass[a][1]='5';
            continue;
        }
        if(digit)
        {
            pass[a][0]='B';
            pass[a][1]='b';
            continue;
        }
    }
    for(int i=0;i<t;i++) cout << pass[i] << endl;
    return 0;
}