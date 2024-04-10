#include <iostream>
#include <algorithm>
#include <vector>

#define NMAX (2*100005)
using namespace std;

int frecv[NMAX];
int v[NMAX];

vector<int> graf[NMAX];

struct op
{
    int l,r;
    int poz;
    int ans;
}toate[NMAX];

bool cmp1(const op &a,const op &b)
{
    return (a.r<b.r);
}

bool cmp2(const op &a,const op &b)
{
    return (a.poz<b.poz);
}

#define lsb(x) ((x)&(-x))
int aib[NMAX];
int n;

inline void add(int poz,int val)
{
    for(int i=poz;i<=n;i+=lsb(i))
        aib[i]+=val;
}

inline int sum(int poz)
{
    int s=0;
    for(int i=poz;i>=1;i-=lsb(i))
        s+=aib[i];

    return s;
}

int main()
{
    int m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        frecv[v[i]]=i;
    }

    for(int i=1;i<=n;i++)
        for(int j=2*i;j<=n;j+=i)
            if(frecv[i] && frecv[j])
                graf[max(frecv[i],frecv[j])].push_back(min(frecv[i],frecv[j]));

    for(int i=1;i<=m;i++){
        cin>>toate[i].l>>toate[i].r;
        toate[i].poz=i;
    }

    sort(toate+1,toate+m+1,cmp1);
    int j=1;

    int puse=0;
    for(int i=1;i<=n;i++){
        for(vector<int>::iterator it=graf[i].begin();it!=graf[i].end();it++){
            add(*it,1);
            puse++;
        }
        while(j<=m)
            if(toate[j].r==i){
                toate[j].ans=(puse-sum(toate[j].l-1))+toate[j].r-toate[j].l+1;
                j++;
            }
            else
                break;
    }

    sort(toate+1,toate+m+1,cmp2);
    for(int i=1;i<=m;i++)
        cout<<toate[i].ans<<'\n';

    return 0;
}