#include <bits/stdc++.h>
using namespace std;

const long long N = 100000000000000000;

int main()
{
long long n, k;
cin>>n>>k;
long long a[n+1];
for (int i = 0; i<=n; i++) cin>>a[i];
long long b[n+1];
for (int i = 0; i<=n; i++) b[i] = a[i];
bool c[n+1] = {0};
for (int i = 0; i<n; i++)
{
    if (b[i]%2==0) {b[i+1]+=b[i]/2; b[i] = 0;}
    else {b[i+1]+=(b[i]-1)/2; b[i]=1; c[i] = 1;}
}
//for (int i = 0; i<=n; i++) cout<<b[i]<<' ';
//cout<<endl;
//for (int i = 0; i<=n; i++) cout<<c[i]<<' ';
//cout<<endl;
int first1 = 0;
while ((!c[first1])&&(first1<n)) first1++;

long long change = 0;
if (first1 == n)
{
   // cout<<"LOL"<<endl;
    int count = 0;
    change = b[n];
    int idx = n;
    while ((fabs(change)<=N)&&(idx>=0))
    {
        if (fabs(a[idx]-change)<=k) if ((idx!=n)||(a[idx]-change)!=0) count++;
        change*=2;
        idx--;
    }
    cout<<count; return 0;
}

else
{
   
    while (((b[n]==-1)&&(b[n-1]==1))&&(n>0))
    {
        b[n] = 0;
        b[n-1] = -1;
        n--;
    }
    
    if (n==0)
    {
        change = -1;
        if (fabs(a[0]-change)<=k) cout<<1;
        else cout<<0;
    }
    
    else if (b[n]==0)
    {

        long long deg2 = 1;
        bool more = false;
        for (int i = first1; i<n; i++)
        {
            if ((c[i])&&(!more)) change+=deg2;
            if (!more) deg2*=2;
            if (deg2>N) more = true;
        }
        int count = 0;
        while ((fabs(change)<=N)&&(first1>=0))
        {
            if (fabs(a[first1]-change)<=k) count++;
            change*=2; first1--;
        }
        cout<<count; return 0;
    }
    
    else if (b[n]!=0)
    {
        //cout<<"KEK"<<' ';
        int g = n-1-first1;
        //cout<<g<<endl;
        long long deg2 = 1;
        while ((deg2<N)&&(g>=0))
        {
            deg2*=2; 
            g--;
        }
        //cout<<deg2<<endl;
        if (g!=-1) {cout<<0; return 0;}
        
        if (fabs(b[n])>N/deg2) {cout<<0; return 0;}
        
        change = b[n]*deg2;
        deg2 = 1;
        for (int i = first1; i<n; i++)
        {
            if (c[i]) change+=deg2;
            deg2*=2;
        }
        //cout<<"change"<<' '<<change<<endl;
        int count = 0;
        //cout<<"first1"<<' '<<first1<<endl;
        while ((fabs(change)<=N)&&(first1>=0))
        {
            if (fabs(a[first1]-change)<=k) count++;
            change*=2; first1--;
        }
        cout<<count; return 0;
        
    }
}


}