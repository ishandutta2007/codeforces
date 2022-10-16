#include <iostream>
#include <bitset>
#include <queue>
#include <utility>

using namespace std;

int p[3005];
//bitset<3005> zero;
bitset<3005> nenul;
bitset<3005> unu;

queue<pair<int,int> > coada;
bitset<3005> viz[3005];
int d[3005][3005];

int main()
{
    int n,k,i;
    cin>>n>>k;

    for(i=1;i<=n;i++)
        cin>>p[i];
    for(i=n;i>=1;i--)
    {
        //zero[i]=zero[i+1]|(!p[i]);
        nenul[i]=nenul[i+1]|(p[i]>0);
        unu[i]=unu[i+1]|(p[i]==100);
    }

    if(n==1)
    {
        cout<<"1\n";
        return 0;
    }

    coada.push(make_pair(1,2));
    viz[1][2]=1;
    d[1][2]=0;

    int ans=1;
    while(!coada.empty())
    {
        pair<int,int> aux=coada.front();
        int x=aux.first,y=aux.second;

        coada.pop();

        if(y>n)
            continue;
        if(d[x][y]==k)
            continue;

        if(nenul[y] && p[x]!=100)
            if(!viz[y][y+1])
            {
                viz[y][y+1]=1;
                ans++;

                d[y][y+1]=d[x][y]+1;
                coada.push(make_pair(y,y+1));
            }

        if(nenul[y] && p[x]!=0)
            if(!viz[y+1][y+2])
            {
                viz[y+1][y+2]=1;
                ans++;

                d[y+1][y+2]=d[x][y]+1;
                coada.push(make_pair(y+1,y+2));
            }

        if(!unu[y] && p[x]!=0)
            if(!viz[x][y+1])
            {
                viz[x][y+1]=1;
                ans++;

                d[x][y+1]=d[x][y]+1;
                coada.push(make_pair(x,y+1));
            }
    }
    cout<<ans<<'\n';

    return 0;
}