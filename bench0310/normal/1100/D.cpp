#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int a,b;
pair<int,int> r[667];
int k,rx,ry;

void print(int a,int b)
{
    cout << a << " " << b << endl;
    cout.flush();
}

void update()
{
    cin >> k >> rx >> ry;
}

void play(int kx,int ky)
{
    while(a!=kx||b!=ky)
    {
        for(int i=1;i<667;i++)
        {
            if(r[i].x>a&&r[i].x-a==1)
            {
                print(a+1,b);
                exit(0);
            }
            if(r[i].x<a&&r[i].x-a==-1)
            {
                print(a-1,b);
                exit(0);
            }
            if(r[i].y>b&&r[i].y-b==1)
            {
                print(a,b+1);
                exit(0);
            }
            if(r[i].y<b&&r[i].y-b==-1)
            {
                print(a,b-1);
                exit(0);
            }
        }
        if(a<kx) a++;
        else if(a>kx) a--;
        if(b<ky) b++;
        else if(b>ky) b--;
        print(a,b);
        update();
        if(k==0&&rx==0&&ry==0) exit(1);
        else if(k==-1&&rx==-1&&ry==-1) exit(1);
        else
        {
            r[k].x=rx;
            r[k].y=ry;
        }
    }
}

int main()
{
    cin >> a >> b;
    for(int i=1;i<=666;i++) cin >> r[i].x >> r[i].y;
    play(500,500);
    int q[4];
    for(int i=0;i<4;i++) q[i]=0;
    for(int i=1;i<667;i++)
    {
        if(r[i].x>a&&r[i].y>b) q[0]++;
        else if(r[i].x>a&&r[i].y<b) q[1]++;
        else if(r[i].x<a&&r[i].y<b) q[2]++;
        else q[3]++;
    }
    int idx=0,m=667;
    for(int i=0;i<4;i++)
    {
        if(q[i]<m)
        {
            m=q[i];
            idx=i;
        }
    }
    if(idx==0) play(1,1);
    else if(idx==1) play(1,999);
    else if(idx==2) play(999,999);
    else if(idx==3) play(999,1);
    return 0;
}