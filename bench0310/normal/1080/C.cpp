#include <iostream>

using namespace std;

void color(long long x1,long long y1,long long x2,long long y2);
long long w,b;

struct rect
{
    long long x1,y1,x2,y2;
};

int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        long long n,m;
        cin >> n >> m;
        rect r[2];
        cin >> r[0].x1 >> r[0].y1 >> r[0].x2 >> r[0].y2 >> r[1].x1 >> r[1].y1 >> r[1].x2 >> r[1].y2;
        long long x1=max(r[0].x1,r[1].x1);
        long long x2=min(r[0].x2,r[1].x2);
        long long y1=max(r[0].y1,r[1].y1);
        long long y2=min(r[0].y2,r[1].y2);
        bool overlap=0;
        if(x1<=x2&&y1<=y2) overlap=1;
        color(1,1,m,n);
        long long white=w,black=b;
        long long area1=(r[0].x2-r[0].x1+1)*(r[0].y2-r[0].y1+1);
        long long area2=(r[1].x2-r[1].x1+1)*(r[1].y2-r[1].y1+1);
        long long areaoverlap=(x2-x1+1)*(y2-y1+1);
        color(r[0].x1,r[0].y1,r[0].x2,r[0].y2);
        white-=w;
        black-=b;
        white+=area1;
        if(overlap)
        {
            color(x1,y1,x2,y2);
            white+=w;
            black+=b;
            white-=areaoverlap;
        }
        color(r[1].x1,r[1].y1,r[1].x2,r[1].y2);
        white-=w;
        black-=b;
        black+=area2;
        cout << white << " " << black << endl;
    }
    return 0;
}

void color(long long x1,long long y1,long long x2,long long y2)
{
    long long xlen=(x2-x1+1);
    long long ylen=(y2-y1+1);
    bool wh=((x1+y1)%2);
    if((xlen*ylen)%2==0)
    {
        w=(xlen*ylen)/2;
        b=(xlen*ylen)/2;
    }
    else
    {
        w=(xlen*ylen)/2+(!wh);
        b=(xlen*ylen)/2+(wh);
    }
}