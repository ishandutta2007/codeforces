#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
   // ifstream cin("input.txt");
    int n, k;
    string s;
    cin>>n>>k>>s;
    int a[n], b[n];
    if(s[0]=='a') { a[0]=1; b[0]=0; }
    else          { a[0]=0; b[0]=1; }
    for(int i=1; i<n; i++) { a[i]=a[i-1]+(s[i]=='a'); b[i]=b[i-1]+(s[i]=='b'); }

    // AAAAAAA
    int l=0, r=n;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(l==m) m++;
        bool done=0;
        for(int i=m-1; i<n; i++)
            if(b[i]-(i==m-1?0:b[i-m])<=k)
                done=1;
        if(done) l=m;
        else r=m-1;
    }
    int ans=l;
    l=0, r=n;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(l==m) m++;
        bool done=0;
        for(int i=m-1; i<n; i++)
            if(a[i]-(i==m-1?0:a[i-m])<=k)
                done=1;
        if(done) l=m;
        else r=m-1;
    }
    cout<<max(l,ans);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //ifstream cin("input.txt");
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int p1=0,p2=0;
    for(int i=1; i<n; i++)
    {
        if(a[i]>a[p1]) p1=i;
        if(a[i]<a[p2]) p2=i;
    }
    if(p1>p2) swap(p1,p2);
    cout<<max(n-p1-1,p2);
    return 0;
}
*/