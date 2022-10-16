#include <iostream>

#define int long long int
using namespace std;

int ceil(int x,int y){
    return (x/y+((bool)(x%y)));
}

signed main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    int minim=1000000000000ll;
    int curent;

    for(int i=0;i<=n;i++){
        curent=a*i+b*ceil(n-i,m);
        if(curent<minim)
            minim=curent;
    }

    cout<<minim<<'\n';
    return 0;
}