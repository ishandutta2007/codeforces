#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

map<int,int> harta;
int v[100005];
int aux[100005];

inline void inv(int st,int dr)
{
    int mijl=(st+dr)>>1;
    for(int i=st;i<=mijl;i++)
        swap(v[i],v[dr-(i-st)]);
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        aux[i]=v[i];
    }

    sort(aux+1,aux+n+1);
    for(int i=1;i<=n;i++)
        harta[aux[i]]=i;
    for(int i=1;i<=n;i++)
        v[i]=harta[v[i]];

    int st=1;
    while(1)
        if(v[st]==st){
            st++;
            //cout<<"a mers "<<endl;
        }
        else{
            st--;
            break;
        }
    //cout<<"st e "<<st<<endl;

    int dr=n;
    while(1)
        if(v[dr]==dr)
            dr--;
        else{
            dr++;
            break;
        }
    //cout<<"a ajuns "<<st<<' '<<dr<<endl;

    if(dr<=st){
        cout<<"yes\n";
        cout<<"1 1"<<'\n';
        return 0;
    }

    st++;
    dr--;
    inv(st,dr);
    //cout<<"am facut "<<st<<' '<<dr<<endl;

    for(int i=1;i<=n;i++)
        if(v[i]!=i){
            cout<<"no\n";
            return 0;
        }
    cout<<"yes\n";
    cout<<st<<' '<<dr<<endl;

    return 0;
}