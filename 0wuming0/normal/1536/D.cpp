#include"bits/stdc++.h"
using namespace std;
char s[500005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=1;
        set<int>s;
        int last;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            if(i==0)last=a;
            int l1,l2,l3;
            s.insert(a);
            auto it=s.find(a);
            l2=a;
            l1=l3=1e9+7;
            if(it!=s.begin())
            {
                it--;
                l1=*it;
                it++;
            }
            it++;
            if(it!=s.end())
            {
                l3=*it;
            }//cout<<"<<<"<<i<<" "<<last<<"<<<"<<l1<<" "<<l2<<" "<<l3<<"<<<"<<endl;
            if(l1!=last&&l2!=last&&l3!=last)
            {
                ans=0;
            }
            last=a;
        }
        if(ans)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}