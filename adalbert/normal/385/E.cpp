#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=5e5;
#define int ll
const int md=1e9+7;

int n;

struct matrix
{
    int a[7][7];
    matrix(const matrix& cp)
    {
        for (int i=1;i<=6;i++)
            for (int j=1;j<=6;j++)
            this -> a[i][j]=cp.a[i][j];
    }
    matrix()
    {

    }
};

matrix mult(matrix &a, matrix &b)
{
    matrix c;
    for (int i=1;i<=6;i++)
        for (int j=1;j<=6;j++)
        {
            int now=0;
            for (int l=1;l<=6;l++)
            {
                now+=a.a[i][l]*b.a[l][j]%n;
                now%=n;
            }
            c.a[i][j]=now;
        }

    return(c);
}

matrix pow(matrix &a, int step)
{
    if (step==1) return(a);
    if (step%2==0)
    {
        matrix now=pow(a,step/2);
        return(mult(now,now));
    } else
    {
        matrix now=pow(a,step-1);

        return(mult(a,now));
    }
}


signed main()
{
    int sx,sy,dx,dy,t;
    cin>>n>>sx>>sy>>dx>>dy>>t;
    if (t==0)
    {
        cout<<sx<<' '<<sy;
        return(0);
    }
    matrix b;
    for (int i=1;i<=6;i++)
        for (int j=1;j<=6;j++)
        b.a[i][j]=0;
    b.a[1][1]=1;
    b.a[1][1]=1;
    b.a[1][3]=1;
    b.a[1][4]=1;
    b.a[2][2]=1;
    b.a[2][3]=1;
    b.a[2][4]=1;
    b.a[3][1]=1;
    b.a[3][3]=2;
    b.a[3][4]=1;
    b.a[4][2]=1;
    b.a[4][3]=1;
    b.a[4][4]=2;
    b.a[5][3]=1;
    b.a[5][4]=1;
    b.a[5][5]=1;
    b.a[6][3]=2;
    b.a[6][4]=2;
    b.a[6][5]=1;
    b.a[6][6]=1;

    b=pow(b,t);



    sx--;
    sy--;
    int x=0;
    x+=sx*b.a[1][1]%n;
    x%=n;
    x+=(dx+sx+sy+2)*b.a[3][1]%n;
    x%=n;
    x+=(sy)*b.a[2][1]%n;
    x%=n;
    x+=(dy+sx+sy+2)*b.a[4][1]%n;
    x%=n;
    x+=b.a[6][1]%n;
    x%=n;
    x+=b.a[5][1]%n;
    x+=n;
    x%=n;
    x++;
    cout<<x<<' ';

    int y=0;
    y+=sx*b.a[1][2]%n;
    y%=n;
    y+=(dx+sx+sy+2)*b.a[3][2]%n;
    y%=n;
    y+=(sy)*b.a[2][2]%n;
    y%=n;
    y+=(dy+sx+sy+2)*b.a[4][2]%n;
    y%=n;
    y+=b.a[6][2]%n;
    y%=n;
    y+=b.a[5][2]%n;
    y+=n;
    y%=n;
    y++;
    cout<<y<<' ';
}