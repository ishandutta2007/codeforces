//be name khoda

#include <iostream>
#include <algorithm>
using namespace std;

long long t[500]={1};

void set(long long n,long long &l,long long b[])
{
    while(n)
    {
        //cout<<n<<endl;
        b[l++]=n%2;
        n/=2;
    }
}

void boro(long long &ans,long long i)
{
    for(i;i>=0;i--)
        ans+=t[i];
}

bool check(long long b[],long long i)
{
    for(i;i>=0;i--)
        if(!b[i])
            return 0;
    return 1;
}

int main()
{
   
    for(long long i=1;i<65;i++)
        t[i]=t[i-1]*2;
    long long n;
    cin>>n;
    for(long long j=0;j<n;j++)
    {
        long long l,r;
        cin>>l>>r;
        /*if(l==r)
        {
            cout<<l<<endl;
            continue;
        }*/
        long long la=0,lb=0,a[200]={},b[200]={};
        set(l,la,a);
        set(r,lb,b);
        //cout<<la<<" "<<lb<<endl;
        long long i=lb-1;
        long long ans=0;
        for(i;i>=0;i--)
        {
            if(a[i]!=b[i])
            {
                if(check(b,i))
                    ans+=t[i];
                boro(ans,i-1);
                i=-1;
            }
            else
            {
                if(b[i])
                    ans+=t[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}