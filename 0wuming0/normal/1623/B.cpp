#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<pair<int,int> >st;
        for(int i=0;i<n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            st.insert(make_pair(l,r));
        }
        pair<int,int>s=make_pair(0,0);
        for(auto pr:st)
        {
            if(pr.first!=s.first)printf("%d %d %d\n",pr.first,pr.second,pr.first);
            else printf("%d %d %d\n",pr.first,pr.second,s.second+1);
            s=pr;
        }
    }
    return 0;
}