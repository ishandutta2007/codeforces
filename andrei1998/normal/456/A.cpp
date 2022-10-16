#include <iostream>
#include <algorithm>

using namespace std;

struct laptop
{
    int price;
    int q;
}v[100005];

bool operator<(const laptop &a,const laptop &b)
{
    if(a.price<b.price)
        return 1;
    return 0;
}

int main()
{
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i].price>>v[i].q;
    sort(v+1,v+n+1);

    bool ok=true;
    for(int i=1;i<n;i++)
        if(v[i].q>v[i+1].q){
            ok=false;
            break;
        }

    if(!ok)
        cout<<"Happy Alex\n";
    else
        cout<<"Poor Alex\n";
    return 0;
}