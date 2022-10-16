#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct obst{
    int x;
    int y;
}v[100005];

set<int> setx;
map<int,int> hartax;

struct interv{
    int a,b;

    interv(int a=0,int b=0): a(a), b(b) {}
};

bool operator<(const interv &a,const interv &b){
    return a.b<b.b;
}

vector<interv> lists[300005];

int main()
{
    int n=0,m=0;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        cin>>v[i].x>>v[i].y;
        setx.insert(v[i].x);

        if(v[i].x!=1)
            setx.insert(v[i].x-1);
        if(v[i].x!=n)
            setx.insert(v[i].x+1);

    }

    set<int>::iterator it;
    int i;
    for(it=setx.begin(),i=1;it!=setx.end();it++,i++)
        hartax[*it]=i;

    int liste=i-1;
    for(i=1;i<=m;i++){
        v[i].x=hartax[v[i].x];
        lists[v[i].x].push_back(interv(v[i].y,v[i].y));
    }

    for(i=1;i<=liste;i++)
        lists[i].push_back(interv(0,0));


    for(i=1;i<=liste;i++)
        lists[i].push_back(interv(n+1,n+1));

    for(i=1;i<=liste;i++)
        stable_sort(lists[i].begin(),lists[i].end());

    lists[1][1].a=1;

    /*for(i=1;i<=liste;i++){
        cout<<"lista "<<i<<endl;
        for(int j=0;j<lists[i].size();j++)
            cout<<lists[i][j].a<<' '<<lists[i][j].b<<endl;
    }*/

    int nr1,nr2=lists[1].size()-1,j,k;
    for(i=2;i<=liste;i++){
        nr1=lists[i-1].size()-1;
        nr2=lists[i].size()-1;

        j=1;
        k=1;

        for(;k<=nr2;k++){
            while(j<nr1)
                if(lists[i-1][j].a==lists[i-1][j].b || lists[i-1][j].b-1<=lists[i][k-1].b)
                    j++;
                else
                    break;

            if(lists[i-1][j].a==lists[i-1][j].b || lists[i-1][j].b-1<=lists[i][k-1].b)
                break;

            if(lists[i-1][j].a<=lists[i][k].b)
                lists[i][k].a=max(lists[i][k-1].b+1,lists[i-1][j].a);
        }
    }

    /*for(i=1;i<=liste;i++){
        cout<<"lista "<<i<<endl;
        for(int j=0;j<lists[i].size();j++)
            cout<<lists[i][j].a<<' '<<lists[i][j].b<<endl;
    }*/

    if(lists[liste][nr2].a==lists[liste][nr2].b)
        cout<<"-1\n";
    else
        cout<<2*n-2<<'\n';
    return 0;
}