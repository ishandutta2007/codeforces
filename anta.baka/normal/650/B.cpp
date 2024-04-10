#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, a, b, t;
    cin>>n>>a>>b>>t;
    int add[2*n];
    char ch;
    for(int i=0; i<n; i++) { cin>>ch; add[i]=(ch=='h'?1:b+1); add[i+n]=add[i]; }
    int l=n, r=n, ct=add[n];
    if(ct>t) { cout<<0; return 0; }
    for(l--; l>0; l--) { if(ct+a+add[l]>t) { l++; break; } ct+=a+add[l]; }
    int ans=n-l+1;
    for(r++; r<2*n; r++)
    {
        ct+=a+add[r];
        int rct=ct+min(r-n,n-l)*a;
        while(rct>t) { ct-=add[l]+a; l++; rct=ct+min(r-n,n-l)*a; }
        if(l>n) break;
        ans=max(ans,r-l+1);
    }
    cout<<min(ans,n);
    return 0;
}