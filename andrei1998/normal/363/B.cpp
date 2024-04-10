#include <iostream>

using namespace std;

int v[150005];

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }

    int ans=0;
    int nr=2000000005;

    for(int j=1;(j+k-1)<=n;j++){
        int aux=(v[j+k-1]-v[j-1]);
        if(aux<nr){
            nr=aux;
            ans=j;
        }
    }

    cout<<ans<<'\n';
    return 0;
}