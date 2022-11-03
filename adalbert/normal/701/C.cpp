#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,w,ans,ka,kb,mx,mn,p[10000],k[10000];
string st;
long long binpow (long long l, long long r)
{
    while (r-l>1)
    {
        for (char c='a';c<='z';c++) k[c]=0;
        for (char c='A';c<='Z';c++) k[c]=0;


        int s=(l+r)/2;
        for (int i=0;i<s;i++)
            k[st[i]]++;
        int ch=0;
        int cc=0;

        for (char c='a';c<='z';c++)
            if (k[c]==0 && p[c]!=0) cc++;
        for (char c='A';c<='Z';c++)
            if (k[c]==0 && p[c]!=0) cc++;
        //cout<<l<<' '<<r<<' '<<s<<' '<<ch<<'\n';
        if (cc==0) ch++;


        for (int i=s;i<n;i++)
        {
            cc=0;
            k[st[i-s]]--;
            k[st[i]]++;
            for (char c='a';c<='z';c++)
                if (k[c]==0 && p[c]!=0) cc++;
            for (char c='A';c<='Z';c++)
                if (k[c]==0 && p[c]!=0) cc++;
            if (cc==0) ch++;
        }
      //  cout<<l<<' '<<r<<' '<<s<<' '<<ch<<'\n';
        if (ch==0) l=s; else r=s;
    }
    return(l);
}
int main()
{
    cin>>n;
    cin>>st;
    for (int i=0;i<n;i++)
        p[st[i]]=1;
    ans=binpow (0,n+1);
    //cout<<ans<<'\n';
        for (char c='a';c<='z';c++) k[c]=0;
        for (char c='A';c<='Z';c++) k[c]=0;
        int s=ans;
        for (int i=0;i<s;i++)
            k[st[i]]++;
        int ch=0;
        int cc=0;
        for (char c='a';c<='z';c++)
            if (k[c]==0 && p[c]!=0) cc++;
        for (char c='A';c<='Z';c++)
            if (k[c]==0 && p[c]!=0) cc++;
        if (cc==0) ch++;
        for (int i=s;i<n;i++)
        {
            cc=0;
            k[st[i-s]]--;
            k[st[i]]++;
            for (char c='a';c<='z';c++)
                if (k[c]==0 && p[c]!=0) cc++;
            for (char c='A';c<='Z';c++)
                if (k[c]==0 && p[c]!=0) cc++;
            if (cc==0) ch++;
        }
        if (ch!=0) cout<<ans; else cout<<ans+1;
}