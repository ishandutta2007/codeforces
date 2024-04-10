#include"bits/stdc++.h"
using namespace std;
int a[200005];
int b[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)scanf("%d",b+i);
        b[n+1]=-1;
        b[0]=-2;
        int now=n;
        multiset<int>s;
        for(int i=n;i>=1;i--)
        {
            while(b[now]==b[now+1])
            {
                s.insert(b[now]);
                now--;
            }
            if(a[i]==b[now])
            {
                now--;
            }
            else
            {
                auto it=s.find(a[i]);
                if(it==s.end())
                {
                    cout<<"no"<<endl;
                    goto ne;
                }
                else
                {
                    s.erase(it);
                }
            }
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}