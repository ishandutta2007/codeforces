#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#define NMAX 100005
using namespace std;

struct muchie
{
    int a,b;
    muchie(int c=0,int d=0): a(c),b(d)
    {
        if(a>b)
            swap(a,b);
    }
};

bool operator<(const muchie &a,const muchie &b)
{
    if(a.a<b.a)
        return 1;
    if(a.a>b.a)
        return 0;

    if(a.b<b.b)
        return 1;
    return 0;
}

map<muchie,int> harta;
vector<muchie> v;
set<muchie> fin;

vector<int> graf[NMAX];

int main()
{
    int n=0;
    cin>>n;

    cout<<n-1<<'\n';
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        cout<<"2 "<<a<<' '<<b<<'\n';
        harta[muchie(a,b)]=i;

        //cout<<"harta "<<a<<' '<<b<<harta[muchie(a,b)]<<endl;
        //cout<<"harta "<<b<<' '<<a<<harta[muchie(b,a)]<<endl;

        graf[a].push_back(b);
        graf[b].push_back(a);

        v.push_back(muchie(a,b));
    }

    for(int i=1;i<=n;i++){
        for(vector<int>::iterator it=graf[i].begin();(it+1)!=graf[i].end();it++){
            //cout<<"acum unim muchiile "<<*it<<' '<<i<<' '<<' '<<*(it+1)<<' '<<i<<endl;
            //cout<<harta[muchie(*it,i)]<<' '<<harta[muchie(*(it+1),i)]<<endl;

            fin.insert(muchie(harta[muchie(*it,i)],harta[muchie(*(it+1),i)]));
        }
    }

    for(set<muchie>::iterator it=fin.begin();it!=fin.end();it++)
        cout<<it->a<<' '<<it->b<<'\n';

    return 0;
}