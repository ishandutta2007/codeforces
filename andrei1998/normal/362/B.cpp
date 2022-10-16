#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,scari[3005],i;

    cin>>n>>m;
    for(i=0; i<m; i++)
        cin>>scari[i];
    sort(scari,scari+m);

    if(m>=1)
        if(scari[0]==1 || scari[m-1]==n)
        {
            cout<<"NO\n";
            return 0;
        }

    for(i=2; i<m; i++)
    {
        if(scari[i]==(scari[i-1]+1) && (scari[i-1]==scari[i-2]+1))
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";

    return 0;
}