#include <iostream>
#include <cstring>

using namespace std;

char sir[100005];

char v[11]={'A','H','I','M','O','T','U','V','W','X','Y'};

int main()
{
    int n,i,j;
    cin.get(sir,100005);
    n=strlen(sir);

    bool ok=true;
    for(i=0;i<n;i++)
    {
        if(sir[i]!=sir[n-i-1])
        {
            ok=false;
            break;
        }

        for(j=0;j<11;j++)
            if(v[j]==sir[i])
                break;
        if(j==11)
        {
            ok=false;
            break;
        }
    }

    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}