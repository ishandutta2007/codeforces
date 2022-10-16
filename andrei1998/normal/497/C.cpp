#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int cant[300005];

struct elem {
    int dr;
    int index;

    elem(int dr=0,int index=0): dr(dr), index(index) {}
};

bool operator<(const elem &a,const elem &b){
    return a.dr<b.dr;
}

multiset<elem> Set;

struct interval {
    int st,dr;
    bool tip;
    int index;

    interval (int st=0,int dr=0,bool tip=0,int index=0): st(st), dr(dr), tip(tip), index(index) {}
}v[300005];

bool operator<(const interval &a,const interval &b) {
    if(a.st==b.st)
        return a.tip<b.tip;
    return a.st<b.st;
}

int ans[300005];

int extr(int cap){
    set<elem>::iterator it;

    while(1){
        it=Set.lower_bound(cap);
        if(it==Set.end())
            return -1;

        if(cant[it->index]<=0)
            Set.erase(it);
        else
            break;
    }

    return it->index;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i].st>>v[i].dr;
        v[i].index=i;
        v[i].tip=1;
    }

    int m=0;
    cin>>m;

    for(int i=1;i<=m;i++){
        cin>>v[n+i].st>>v[n+i].dr;
        v[n+i].tip=0;
        v[n+i].index=n+i;
        cin>>cant[n+i];
    }

    sort(v+1,v+n+m+1);

    bool ok=true;

    int poz=n+m,aux;
    for(int i=1;i<=poz;i++)
        if(v[i].tip==0)
            Set.insert(elem(v[i].dr,v[i].index));
        else{
            aux=extr(v[i].dr);

            if(aux==-1){
                ok=false;
                break;
            }

            ans[v[i].index]=aux-n;
            cant[aux]--;
        }

    if(!ok){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    cout<<ans[1];
    for(int i=2;i<=n;i++)
        cout<<' '<<ans[i];
    cout<<'\n';

    return 0;
}