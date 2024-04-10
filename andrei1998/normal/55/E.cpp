#include <iostream>
#include <algorithm>

#define NMAX 300005
#define lint long long int
using namespace std;

struct punct
{
    int x,y;
}v[NMAX];

lint ccw(punct a,punct b,punct c){
    return (1ll*(a.x-c.x)*(b.y-c.y)-1ll*(b.x-c.x)*(a.y-c.y));
}

lint determina(int n,punct centru){
    int j=1;

    lint ans=0;
    for(int i=1;i<=n;i++){
        while((j+1)<=(2*n)){
            if(ccw(v[i],centru,v[j+1])>=0ll){
                j++;
            }
            else
                break;
        }

        ans+=max(0ll,((j-i-1ll)*(j-i))/2);
    }

    return ans;
}

int main()
{
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i].x>>v[i].y;
        v[n+i]=v[i];
    }

    lint total=(1ll*n*(n-1)*(n-2))/6;

    int t=0;
    cin>>t;

    punct centru;
    while(t--){
        cin>>centru.x>>centru.y;

        bool ok=true;

        for(int i=1;i<=n;i++)
            if(ccw(centru,v[i],v[i+1])>=0){
                ok=false;
                break;
            }

        if(!ok)
            cout<<"0\n";
        else
            cout<<total-determina(n,centru)<<'\n';
    }

    return 0;
}