#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int n,m,k,x,y,check=1;
        cin>>n>>m>>k;
        cin>>y;
        for (int i=2;i<=n;i++)
        {
            scanf("%d",&x);
            if (y<x-k) m-=x-k-y;
            else m+=y-max(x-k,0);
            if (m<0) check=0;
            y=x;
        }
        if (check) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}