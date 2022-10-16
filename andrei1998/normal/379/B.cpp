#include <iostream>

using namespace std;

#define lsb(x) (x&(-x))

int aib[305];
int n;

int sum(int poz)
{
    int s=0;
    for(;poz>0;poz-=lsb(poz))
        s+=aib[poz];
    return s;
}

inline void update(int poz,int val)
{
    for(;poz<=n;poz+=lsb(poz))
        aib[poz]+=val;
}

int main()
{
    int i;
    int v[305];
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        update(i,v[i]);
    }

    int poz=1;
    while(poz<=n)
    {
        if(v[poz]>0)
        {
            cout<<'P';
            v[poz]--;
            update(poz,-1);
        }

        if(sum(poz-1)>0 || (poz==n && v[n]>0))
        {
            cout<<'L';
            poz--;
        }
        else
        {
            if(poz<n)
                cout<<'R';
            poz++;
        }
    }
    cout<<'\n';

    return 0;
}