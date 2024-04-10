#include"bits/stdc++.h"
using namespace std;
#define ll long long
map<int,int>boy[200005];
int bb[200005];
int gg[200005];
int bnum[200005],gnum[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        for(int i=0;i<n;i++)scanf("%d",bb+i);
        for(int i=0;i<n;i++)scanf("%d",gg+i);
        for(int i=0;i<n;i++)
        {
            boy[bb[i]][gg[i]]=1;
            bnum[bb[i]]++;
            gnum[gg[i]]++;
        }
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            bnum[bb[i]]--;
            gnum[gg[i]]--;
            ans=ans+i-bnum[bb[i]]-gnum[gg[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}