#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

int main()
{
    //ifstream cin("mafia.in");
    //ofstream cout("mafia.out");

    int n=0,maxim=0;
    lint s=0;

    cin>>n;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;

        s+=x;
        maxim=max(maxim,x);
    }

    lint r=s/(n-1);

    if(s%(n-1)!=0)
        r++;

    cout<<max(1ll*maxim,r)<<'\n';

    //cin.close();
    //cout.close();
    return 0;
}