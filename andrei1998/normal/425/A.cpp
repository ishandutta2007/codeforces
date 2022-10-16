#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct elem
{
    int val;
    int poz;
}sortate[205];
bool tip[205];

bool operator<(const elem &a,const elem &b)
{
    if(a.val<b.val)
        return 1;
    return 0;
}

int aux[205];
int v[205];
int n;

inline void cop()
{
    int i;
    for(i=1;i<=n;i++)
        v[i]=aux[i];
}

int ssmax(int l,int r)
{
    int s=0;
    for(int i=l;i<=r;i++)
        s+=v[i];

    return s;
}

int main()
{
    int k,i,j,l;

    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>aux[i];
        sortate[i].poz=i;
        sortate[i].val=aux[i];
    }
    sort(sortate+1,sortate+n+1);

    int maxim=-1001;

    vector<int> de_scos;
    vector<int> de_pus;

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            cop();
            de_scos.clear();
            de_pus.clear();

            for(l=1;l<=n;l++)
                if(sortate[l].poz>=i && sortate[l].poz<=j)
                    tip[l]=1;
                else
                    tip[l]=0;

            int alese=0;
            for(l=1;l<=n && alese<k;l++)
                if(tip[l])
                {
                    de_scos.push_back(sortate[l].poz);

                    alese++;
                }

            alese=0;
            for(l=n;l>=1 && alese<k;l--)
                if(!tip[l])
                {
                    de_pus.push_back(sortate[l].poz);
                    alese++;
                }


            for(l=0;l<de_scos.size() && l<de_pus.size();l++)
                if(v[de_scos[l]]<v[de_pus[l]])
                    swap(v[de_scos[l]],v[de_pus[l]]);

            maxim=max(maxim,ssmax(i,j));
        }
    }
    cout<<maxim<<'\n';

    return 0;
}