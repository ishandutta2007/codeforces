#include <bits/stdc++.h>
using namespace std;

int get(int x, int a[], int n)
{
    int l=0, r=n;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(l==m) m++;
        (x>a[m]?l=m:r=m-1);
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, s, d;
    cin>>n>>m>>s>>d;
    int a[n+1];
    a[n]=-1;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n+1);
    if(a[1]<=s) { cout<<"IMPOSSIBLE"; return 0; }
    bool can[n];
    for(int i=0; i<n; i++)
        can[i]=(a[i+1]-a[i]>=s+2);
    int to[n];
    to[0]=0;
    for(int i=1; i<n; i++)
        to[i]=(can[i]?i:to[i-1]);

    vector<int> ans;
    int cur=0;
    for(;;)
    {
        ans.push_back(a[cur+1]-a[cur]-2);
        int aj=a[cur+1]+d-1;
        if(aj>a[n])
        {
            ans.push_back(a[n]-a[cur+1]+2);
            if(m>a[n]+1)
                ans.push_back(m-a[n]-1);
            break;
        }
        int gto=to[get(aj,a,n)];
        if(gto==cur)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        ans.push_back(a[gto]-a[cur+1]+2);
        cur=gto;
    }

    for(int i=0; i<ans.size(); i++)
        cout<<(i%2?"JUMP ":"RUN ")<<ans[i]<<endl;
    return 0;
}