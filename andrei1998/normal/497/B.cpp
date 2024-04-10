#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n;
int v[100005];

int s_part0[100005];
int s_part1[100005];

inline int _0s(int st,int dr){
    return s_part0[dr]-s_part0[st-1];
}

inline int _1s(int st,int dr){
    return s_part1[dr]-s_part1[st-1];
}

inline bool won(int s,int st,int dr){
    if(_0s(st,dr)>=s || _1s(st,dr)>=s)
        return true;
    return false;
}

vector<pair<int,int> > sol;

int bs(int s,int l) {
    if(!won(s,l,n))
        return 0;

    int st=l;
    int dr=n; //or n-1
    int rasp=n;
    int mijl=(st+dr)>>1;

    while(st<=dr){
        if(won(s,l,mijl)){
            rasp=mijl;
            dr=mijl-1;
        }
        else{
            st=mijl+1;
        }

        mijl=(st+dr)>>1;
    }

    return rasp;
}

int check(int s) {
    int ultim=-1;
    int pr=0;
    int nd=0;

    int aux;
    for(int i=1;i<=n;i=aux+1){
        aux=bs(s,i);

        if(!aux)
            return 0;

        if(_0s(i,aux)==s){
            pr++;
            ultim=0;
        }
        else{
            nd++;
            ultim=1;
        }
    }

    if(pr==nd)
        return 0;
    if(pr<nd){
        if(ultim==1)
            return nd;
        return 0;
    }

    if(ultim==0)
        return pr;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==2)
            v[i]=0;
    }

    for(int i=1;i<=n;i++){
        s_part0[i]=s_part0[i-1];
        s_part1[i]=s_part1[i-1];

        if(v[i]==0)
            s_part0[i]++;
        else
            s_part1[i]++;
    }

    int aux;
    for(int s=1;s<=n+1;s++){
        aux=check(s);

        if(aux!=0)
            sol.push_back(make_pair(aux,s));
    }

    sort(sol.begin(),sol.end());

    cout<<sol.size()<<'\n';
    for(int i=0;i<sol.size();i++)
        cout<<sol[i].first<<' '<<sol[i].second<<'\n';
    return 0;
}