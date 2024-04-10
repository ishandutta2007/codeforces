#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        set<int>st;
        for(int i=0;i<n;i++)st.insert(a[i]);
        auto it=st.begin();
        int ans=0;
        for(int i=0;i<n;)
        {//cout<<"<<"<<i<<endl;
            int r=i;
            while(r<n&&a[i]==a[r])r++;
            int s=r-i;
            if(r==n)
            {
                ans=max(s,ans);
                break;
            }
            int last=a[r];
            s++;
            while(1)
            {//cout<<"!!"<<last<<endl;
                it=st.lower_bound(2*last-a[i]);
                if(it==st.end())break;
                s++;
                last=*it;
            }
            ans=max(s,ans);
            i=r;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
/*
1000
5
1 4 6 7 7
*/