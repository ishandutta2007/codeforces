#include <iostream>

using namespace std;

int ql,qr;
int v[100005];

int add(int a,int b){
    if(a==b)
        return 0;
    if(a<b)
        return ((b-a-1)*qr);
    return ((a-b-1)*ql);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0,l,r;
    cin>>n>>l>>r>>ql>>qr;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }

    int ans=2000000005;
    int aux;
    for(int i=0;i<=n;i++){
        aux=add(i,n-i)+l*v[i]+(v[n]-v[i])*r;

        if(aux<ans)
            ans=aux;
    }

    cout<<ans<<'\n';
    return 0;
}