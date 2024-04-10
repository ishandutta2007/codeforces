#include <iostream>
#include <algorithm>
#include <string>

#define M 120
#define f first
#define s second
#define mp make_pair

using namespace std;

int n,m,a[M],t=0,b[M];
pair<int,bool> p[M];
bool u[M];

void read(void){
    cin>>m>>n;
    string s;
    
    for (int i=0; i<m; ++i){
        cin>>s>>p[i].f;
        
        p[i].s=(s[0]=='D');
        
        if (s[0]=='A')
        b[t]=p[i].f,t++;
        else
        p[i].f++;
    }
    for (int i=0; i<n; ++i)
    cin>>a[i];
    
    sort(p,p+m);
    sort(a,a+n);
    sort(b,b+t);
}

int che(int k){
    int ans=0;
    for (int i=k-1; i>=0; --i)
    if (a[n-k+i]<b[i])
    return -1;
    else
    ans=ans+a[n-k+i]-b[i];
    return ans;
}

int fle(int k){
    for (int i=0; i<n; ++i)
    if (!u[i] && a[i]>=k)
    return i;
    return -1;
}

int lge(int k){
    for (int i=n-1; i>=0; --i)
    if (!u[i] && a[i]>=k)
    return i;
    return -1;
}

int greed(void){
    int ans=0;
    for (int i=m-1; i>=0; --i){
        int k;
        
        if (p[i].s)
        k=fle(p[i].f);
        else
        k=lge(p[i].f);
        
        if (k==-1)
        return -1;
        
        u[k]=1;
        if (!p[i].s)
        ans=ans+a[k]-p[i].f;
    }
    
    for (int i=0; i<n; ++i)
    if (!u[i])
    ans+=a[i];
    
    return ans;
}

void kill(void){
    int ans=0;
    for (int i=0; i<=n && i<=t; ++i)
    ans=max(ans,che(i));
    
    ans=max(ans,greed());

    
    cout<<ans<<"\n";
    
}

int main()
{
    read();
    kill();
    return 0;
}