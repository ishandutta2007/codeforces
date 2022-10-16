#include <iostream>

using namespace std;

int frecv[100005];

int main()
{
    int n,k;
    cin>>n>>k;

    if(n==1){
        if(!k)
            cout<<"1\n";
        else
            cout<<"-1\n";

        return 0;
    }

    if(k<(n/2)){
        cout<<"-1\n";
        return 0;
    }
    k-=(n/2);
    k++;

    cout<<2*k<<' '<<k;

    if(2*k<=100005)
        frecv[2*k]=frecv[k]=1;
    else if(k<=100005)
        frecv[k]=1;

    int j=1;
    for(int i=4;i<=n;i+=2){
        while(frecv[j] || frecv[j+1])
            j++;
        cout<<' '<<j<<' '<<j+1;
        frecv[j]=frecv[j+1]=1;
    }

    if(n&1){
        while(frecv[j])
            j++;
        cout<<' '<<j;
    }
    cout<<'\n';

    return 0;
}