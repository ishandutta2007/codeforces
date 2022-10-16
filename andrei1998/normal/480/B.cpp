#include <iostream>
#include <set>

using namespace std;

int v[100005];
set<int> Set;
set<int> Set_x;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,l,x,y;
    cin>>n>>l>>x>>y;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        Set.insert(v[i]);
    }

    bool ex_x=false;
    bool ex_y=false;
    for(int i=1;i<=n;i++){
        if(Set.count(v[i]+x) || Set.count(v[i]-x))
            ex_x=true;

        if(Set.count(v[i]+y) || Set.count(v[i]-y))
            ex_y=true;
    }

    if(ex_x && ex_y){
        cout<<"0\n";
        return 0;
    }
    else if(ex_x){
        cout<<"1\n";
        cout<<y<<'\n';

        return 0;
    }
    else if(ex_y){
        cout<<"1\n";
        cout<<x<<'\n';

        return 0;
    }

    for(int i=1;i<=n;i++){
        if(v[i]+x<=l)
            Set_x.insert(v[i]+x);
        if(v[i]-x>=0)
            Set_x.insert(v[i]-x);
    }

    for(int i=1;i<=n;i++){
        if(v[i]+y<=l){
            if(Set_x.count(v[i]+y)){
                cout<<"1\n";
                cout<<v[i]+y<<'\n';
                return 0;
            }
        }
        if(v[i]-y>=0){
            if(Set_x.count(v[i]-y)){
                cout<<"1\n";
                cout<<v[i]-y<<'\n';
                return 0;
            }
        }
    }

    cout<<"2\n";
    cout<<x<<' '<<y<<'\n';
    return 0;
}