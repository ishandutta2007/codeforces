#include <iostream>

using namespace std;

bool viz[1005];

int main()
{
    int n=1;
    cin>>n;

    int poz=0;
    for(int i=1;i<=1000005;i++){
        viz[poz]=1;

        poz+=i;
        poz%=n;
    }

    bool ok=true;
    for(int i=0;i<n;i++)
        if(!viz[i]){
            ok=false;
            break;
        }

    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}