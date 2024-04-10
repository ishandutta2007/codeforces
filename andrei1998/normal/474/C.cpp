#include <iostream>
#include <vector>
#include <algorithm>

#define int long long int
using namespace  std;

struct punct{
    int x,y;

    punct(int x=0,int y=0): x(x), y(y) {}
};

struct punct2
{
    punct a[4];
}v[4][105];

int dist(const punct &a,const punct &b){
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool drept(const punct &a,const punct &b,const punct &c){
    return (dist(a,b)+dist(b,c)==dist(a,c));
}

punct spec;
bool operator<(const punct &a,const punct &b){
    return dist(a,spec)<dist(b,spec);
}

bool patrat(punct a,punct b,punct c,punct d){
    vector<punct> v;

    spec=a;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    sort(v.begin(),v.end());

    if(!dist(spec,v[3]))
        return false;
    return (dist(v[0],v[1])==dist(v[1],v[3]) && dist(v[0],v[1])==dist(v[0],v[2]) && dist(v[0],v[1])==dist(v[2],v[3]) && drept(v[1],v[0],v[2]));
}

signed main()
{
    int n=0;
    cin>>n;

    int a,b,k;
    for(int i=1;i<=n;i++)
        for(k=0;k<4;k++){
            cin>>v[k][i].a[0].x>>v[k][i].a[0].y;
            cin>>a>>b;

            v[k][i].a[1].x= a+b-v[k][i].a[0].y;
            v[k][i].a[1].y=-a+b+v[k][i].a[0].x;

            v[k][i].a[2].x=2*a-v[k][i].a[0].x;
            v[k][i].a[2].y=2*b-v[k][i].a[0].y;

            v[k][i].a[3].x=a-b+v[k][i].a[0].y;
            v[k][i].a[3].y=a+b-v[k][i].a[0].x;
        }

    int j,minim;

    int l,p;
    for(int i=1;i<=n;i++){
        minim=30;
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(l=0;l<4;l++)
                    for(p=0;p<4;p++)
                        if(patrat(v[0][i].a[j],v[1][i].a[k],v[2][i].a[l],v[3][i].a[p]))
                            if(j+k+l+p<minim)
                                minim=j+k+l+p;

        if(minim==30)
            cout<<"-1\n";
        else
            cout<<minim<<'\n';
    }

    return 0;
}