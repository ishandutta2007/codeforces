#include <iostream>
#include <bitset>

using namespace std;

struct punct
{
    int x;
    int y;
}v[10];

inline int dist(punct a,punct b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline bool drept(punct a,punct b,punct c)
{
    return ((dist(a,b)+dist(b,c))==(dist(a,c)));
}

bitset<10> viz;
int sol[10];
bool found;

inline bool dreptunghi(punct a,punct b,punct c,punct d)
{
    return ((dist(a,b)==dist(c,d)) && (dist(a,d)==dist(c,b)) && drept(a,b,c));
}

inline bool patrat(punct a,punct b,punct c,punct d)
{
    return (dreptunghi(a,b,c,d) && dist(a,b)==dist(b,c));
}

inline bool ok()
{
    return (patrat(v[sol[1]],v[sol[2]],v[sol[3]],v[sol[4]]) && dreptunghi(v[sol[5]],v[sol[6]],v[sol[7]],v[sol[8]]));
}

void backtr(int poz)
{
    if(poz==9)
    {
        if(ok())
        {
            int i;
            found=true;
            cout<<"YES\n";

            cout<<sol[1];
            for(i=2;i<=4;i++)
                cout<<' '<<sol[i];

            cout<<'\n'<<sol[5];
            for(i=6;i<=8;i++)
                cout<<' '<<sol[i];
            cout<<'\n';
        }
        return;
    }

    int i;
    for(i=1;i<=8;i++)
        if(!viz[i])
        {
            viz[i]=1;
            sol[poz]=i;

            backtr(poz+1);
            if(found)
                return;

            viz[i]=0;
        }
}

int main()
{
    int i;
    for(i=1;i<=8;i++)
        cin>>v[i].x>>v[i].y;

    backtr(1);

    if(!found)
        cout<<"NO\n";

    return 0;
}