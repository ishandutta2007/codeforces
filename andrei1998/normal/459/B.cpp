#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> flori;
int v[200005];

int main()
{
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        flori[v[i]]++;
    }

    sort(v+1,v+n+1);

    bool ok=true;
    for(int i=2;i<=n;i++)
        if(v[i]!=v[1]){
            ok=false;
            break;
        }

    if(ok){
        cout<<"0 "<<(1ll*n*(n-1ll))/2ll<<'\n';
        return 0;
    }

    int a=v[1];
    int b=v[n];
    cout<<b-a<<' '<<1ll*flori[a]*flori[b]<<'\n';

    return 0;
}