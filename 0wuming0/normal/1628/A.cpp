#include"bits/stdc++.h"
using namespace std;
int a[200005];
int b[200005];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            mp[a[i]]++;
        }
        nn=0;
        int l=0;
        while(l<n)
        {
            int k;
            for(k=0;;k++)
            {
                if(mp[k]==0)break;
            }
            if(k==0)
            {
                mp[a[l]]--;
                l++;
                b[nn++]=0;
                continue;
            }
            set<int>st;
            for(int i=0;i<k;i++)st.insert(i);
            while(st.size())
            {
                if(st.find(a[l])!=st.end())
                {
                    st.erase(st.find(a[l]));
                }
                mp[a[l]]--;
                l++;
            }
            b[nn++]=k;
        }
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%d%c",b[i]," \n"[i==nn-1]);
    }
    return 0;
}