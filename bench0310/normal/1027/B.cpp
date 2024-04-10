#include <iostream>

using namespace std;

long long ceil(double n);
long long floor(double n);
long long up(long long n,long long first);
long long left(long long x,long long first,long long n);

int main()
{
    long long n,q;
    cin >> n >> q;
    long long c[q][2];
    for(long long i=0;i<q;i++) cin >> c[i][0] >> c[i][1];
    long long first=ceil(n*n/2.0);
    if(n%2==1)
    {
        /*long long up[n+1];
        up[1]=1;
        up[2]=first+1;
        long long left[n+1];
        left[1]=1;
        left[2]=first+ceil(n/2.0);
        for(long long i=3;i<=n;i++)
        {
            up[i]=up[i-2]+1;
            left[i]=left[i-2]+n;
        }*/
        long long x,y;
        long long jump=ceil(n/2.0);
        for(long long i=0;i<q;i++)
        {
            x=c[i][0]; y=c[i][1];
            if(x==y) cout << 1+(x-1)*jump << endl;
            else if(x<y) cout << up(y-x+1,first)+(x-1)*jump << endl;
            else if(x>y) cout << left(x-y+1,first,n)+(y-1)*jump << endl;
        }
    }
    else
    {
        for(int i=0;i<q;i++)
        {
            if((c[i][0]+c[i][1])%2==0) cout << (n/2)*(c[i][0]-1)+ceil(c[i][1]/2.0) << endl;
            else cout << (n/2)*(c[i][0]-1)+ceil(c[i][1]/2.0)+first << endl;
        }
    }


    return 0;
}

long long ceil(double n)
{
    if((long long)n==n) return (long long)n;
    else return (long long)(n+0.5);
}

long long floor(double n)
{
    if((long long)n==n) return (long long)n;
    else return (long long)(n-0.5);
}

long long up(long long n,long long first)
{
    if(n%2==1) return ceil(n/2.0);
    else return first+n/2;
}

long long left(long long x,long long first,long long n)
{
    if(x%2==1) return 1+floor(x/2.0)*n;
    else return first+ceil(n/2.0)+(((x/2)-1)*n);
}