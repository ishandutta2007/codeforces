#include <iostream>

using namespace std;

int abs(int x);

int main()
{
    int n,h,a,b,k;
    cin >> n >> h >> a >> b >> k;
    int q[k][4];
    for(int o=0;o<k;o++)
    {
        for(int i=0;i<4;i++)
        {
            cin >> q[o][i];
        }
    }
    for(int i=0;i<k;i++)
    {
        if(q[i][0]==q[i][2])
        {
            cout << abs(q[i][1]-q[i][3]) << endl;
            continue;
        }
        if(q[i][1]>=a && q[i][1]<=b)
        {
            cout << abs(q[i][0]-q[i][2])+abs(q[i][1]-q[i][3]) << endl;
            continue;
        }
        if(q[i][1]<a)
        {
            cout << a-q[i][1]+abs(q[i][0]-q[i][2])+abs(a-q[i][3]) << endl;
            continue;
        }
        if(q[i][1]>b)
        {
            cout << q[i][1]-b+abs(q[i][0]-q[i][2])+abs(b-q[i][3]) << endl;
        }
    }
    return 0;
}

int abs(int x)
{
    if(x>=0) return x;
    return -x;
}