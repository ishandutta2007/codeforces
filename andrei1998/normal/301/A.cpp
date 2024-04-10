#include <iostream>
#include <cmath>

using namespace std;

int v[505];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=(2*n-1);i++)
        cin>>v[i];

    if(n%2==1){
        int s=0;
        for(int i=1;i<=(2*n-1);i++)
            s+=abs(v[i]);
        cout<<s<<'\n';

        return 0;
    }

    int pozcount=0;
    for(int i=1;i<=(2*n-1);i++)
        if(v[i]>=0)
            pozcount++;

    if(pozcount%2==1){
        int s=0;
        for(int i=1;i<=(2*n-1);i++)
            s+=abs(v[i]);
        cout<<s<<'\n';

        return 0;
    }

    int s=0;
    for(int i=1;i<=(2*n-1);i++)
        s+=abs(v[i]);

    int minim=1005;
    for(int i=1;i<=(2*n-1);i++)
        if(abs(v[i])<minim)
            minim=abs(v[i]);
    s-=2*minim;

    cout<<s<<'\n';
    return 0;
}