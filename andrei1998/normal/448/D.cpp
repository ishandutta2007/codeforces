#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

long long int bs_lin(long long int x)
{
    //cout<<"bs_lin("<<x<<")\n";
    long long int rasp=0;
    for(long long int i=1;i<=n;i++)
        rasp+=min((x/i),1ll*m);
    //cout<<"egal "<<rasp<<endl;

    return rasp;
}

int main()
{
    long long int k;
    cin>>n>>m>>k;

    long long int st=1;
    long long int dr=1ll*n*m;
    long long int mijl=(st+dr)>>1;

    while(st<=dr){
        long long int low=bs_lin(mijl-1);
        long long int high=bs_lin(mijl);
        //cout<<mijl<<' '<<low<<' '<<high<<endl;

        if(low<k && k<=high){
            cout<<mijl<<'\n';
            return 0;
        }
        else if(k>high){
            st=mijl+1;
        }
        else
            dr=mijl-1;

        mijl=(st+dr)>>1;
    }

    return 0;
}