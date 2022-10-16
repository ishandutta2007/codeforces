#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> harta;
int n;
int v[1000005];
int f1[1000005];
int f2[1000005];

#define lsb(x) ((x)&(-x))
int aib[1000005];

inline void update(int poz)
{
    for(;poz<=n;poz+=lsb(poz))
        aib[poz]++;
}

inline int query(int poz)
{
    int s=0;
    for(;poz;poz-=lsb(poz))
        s+=aib[poz];

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    reverse(v+1,v+n+1);

    for(int i=1;i<=n;i++){
         harta[v[i]]++;
         f1[i]=harta[v[i]];
    }

    harta.clear();
    for(int i=n;i>=1;i--){
        harta[v[i]]++;
        f2[i]=harta[v[i]];
    }

    long long int ans=0;
    for(int i=1;i<=n;i++){
        ans+=query(f2[i]-1);

        update(f1[i]);
    }

    cout<<ans<<'\n';
    return 0;
}