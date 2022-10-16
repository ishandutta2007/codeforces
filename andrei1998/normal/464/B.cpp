#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

struct punct
{
    int x,y,z;
    punct(int x=0,int y=0,int z=0): x(x), y(y), z(z) {}
};

punct rf;
long long int dist(const punct &a,const punct &b)
{
    return ((1ll*a.x-b.x)*(a.x-b.x)+(1ll*a.y-b.y)*(a.y-b.y)+(1ll*a.z-b.z)*(a.z-b.z));
}

bool operator<(const punct &a,const punct &b){
    return (dist(rf,a)<dist(rf,b));
}

bool tr_drept(punct &a,punct &b,punct &c){
    return (dist(a,b)+dist(b,c)==dist(a,c));
}

struct set_pct
{
    punct v[8];

    bool cub(){
    if(!tr_drept(v[1],v[0],v[2]))
        return 0;
    if(!tr_drept(v[3],v[0],v[2]))
        return 0;
    if(!tr_drept(v[1],v[0],v[3]))
        return 0;

    if(!tr_drept(v[4],v[7],v[5]))
        return 0;
    if(!tr_drept(v[6],v[7],v[5]))
        return 0;
    if(!tr_drept(v[4],v[7],v[6]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[0],v[2]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[0],v[3]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[7],v[4]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[7],v[5]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[7],v[6]))
        return 0;


    if(dist(v[0],v[1])!=dist(v[3],v[6]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[2],v[6]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[1],v[4]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[1],v[5]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[4],v[2]))
        return 0;

    if(dist(v[0],v[1])!=dist(v[5],v[3]))
        return 0;
    return dist(v[0],v[1]);
}
}init;

bool ok=false;
void backtr(int poz){
    if(poz==8){
        set_pct y=init;
        rf=y.v[0];

        sort(y.v,y.v+8);

        swap(y.v[4],y.v[5]);
        if(y.cub())
            ok=true;

        swap(y.v[6],y.v[5]);
        if(y.cub())
            ok=true;

        swap(y.v[4],y.v[6]);
        if(y.cub())
            ok=true;

        swap(y.v[4],y.v[5]);
        if(y.cub())
            ok=true;

        swap(y.v[6],y.v[5]);
        if(y.cub())
            ok=true;

        swap(y.v[4],y.v[6]);
        if(y.cub())
            ok=true;

        return;
    }


    swap(init.v[poz].x,init.v[poz].y);
    backtr(poz+1);
    if(ok)
        return;

    if(!poz){
        swap(init.v[poz].x,init.v[poz].y);
        return;
    }

    swap(init.v[poz].y,init.v[poz].z);
    backtr(poz+1);
    if(ok)
        return;

    swap(init.v[poz].z,init.v[poz].x);
    backtr(poz+1);
    if(ok)
        return;

    swap(init.v[poz].x,init.v[poz].y);
    backtr(poz+1);
    if(ok)
        return;

    swap(init.v[poz].y,init.v[poz].z);
    backtr(poz+1);
    if(ok)
        return;

    swap(init.v[poz].z,init.v[poz].x);
    backtr(poz+1);
    if(ok)
        return;
}

int main()
{
    for(int i=0;i<8;i++)
        cin>>init.v[i].x>>init.v[i].y>>init.v[i].z;

    backtr(0);
    if(ok){
        cout<<"YES\n";
        for(int i=0;i<8;i++)
            cout<<init.v[i].x<<' '<<init.v[i].y<<' '<<init.v[i].z<<'\n';
        return 0;
    }

    cout<<"NO\n";
    return 0;
}