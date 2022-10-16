#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,i,poz=2;
    char sir_cerut[300005];
    char sir[300005];
    sir_cerut[0]='<';
    sir_cerut[1]='3';
    cin>>n;
    int j,lung;
    for(i=0;i<n;i++)
    {
        cin.get();
        cin.get(sir,300005);
        lung=strlen(sir);
        for(j=0;j<lung;j++)
            sir_cerut[poz+j]=sir[j];
        poz+=lung;
        sir_cerut[poz]='<';
        sir_cerut[poz+1]='3';
        poz+=2;
    }
    cin.get();
    cin.get(sir,300005);
    lung=strlen(sir);
    int unde=0;
    for(i=0;i<lung;i++)
        if(unde<poz && sir_cerut[unde]==sir[i])
            unde++;
    if(unde==poz)
        cout<<"yes\n";
    else
        cout<<"no\n";
    return 0;
}