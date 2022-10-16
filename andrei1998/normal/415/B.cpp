#include <iostream>

using namespace std;

int ans(int a,int b,int w)
{
    int st=0;
    int dr=w;
    int mijl=(w>>1);
    int ans=w;

    long long int val=((1ll*w*a)/b);
    while(st<=dr){
        long long int val1=((1ll*mijl*a)/b);
        if(val1<val){
            st=mijl+1;
        }
        else if(val1==val){
            dr=mijl-1;
            ans=mijl;
        }

        mijl=(st+dr)>>1;
    }

    return ans;
}

int main()
{
    int n=0,a,b;
    cin>>n>>a>>b;

    int w=1;
    for(int i=1;i<=n;i++){
        cin>>w;

        cout<<w-ans(a,b,w)<<'\n';
    }

    return 0;
}