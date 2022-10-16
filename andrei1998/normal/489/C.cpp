#include <iostream>

using namespace std;

inline bool pos(int l,int s,bool ok){
    if(ok)
        return (0<=s && s<=9*l);
    return (1<=s && s<=9*l);
}

int main()
{
    int l,s;
    cin>>l>>s;

    if(l==1 && !s){
        cout<<"0 0\n";
        return 0;
    }

    if(!pos(l,s,0)){
        cout<<"-1 -1\n";
        return 0;
    }

    int k,aux=s;
    bool ok=0;

    for(int i=1;i<=l;i++){
        for(k=1-ok;k<=9;k++)
        if(pos(l-i,s-k,1)){
            cout<<k;
            ok=1;

            s-=k;
            break;
        }
    }

    s=aux;
    ok=0;

    cout<<" ";
    for(int i=1;i<=l;i++){
        for(k=9;k>=1-ok;k--)
        if(pos(l-i,s-k,1)){
            cout<<k;
            ok=1;

            s-=k;
            break;
        }
    }

    return 0;
}