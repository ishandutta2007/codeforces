#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char sir[100005];
int v[100005];

int main()
{
    cin.get(sir+1,100005);
    int n=strlen(sir+1),i;
    string x="";

    int s=0;
    for(i=1;i<=n;i++)
    {
        v[i]=sir[i]-'0';
        s+=v[i];

        if(!v[i] && s==(i-1))
        {
            ;
        }
        else
            x+=sir[i];
    }
    if(s==n)
        x=x.substr(1,n-1);

    cout<<x<<'\n';

    return 0;
}