#include"bits/stdc++.h"
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    int mn=n;
    for(int i=n;i>=1;i--)if(a[i]==0)
    {
        vector<int>v;
        v.push_back(i);
        for(int j=2;j<=n;j++)
        {
            cout<<"?";
            for(int k=1;k<=n;k++)
            {
                if(k==i)cout<<" "<<j;
                else cout<<" "<<1;
            }
            cout<<endl;
            int c;
            cin>>c;
            if(c==0||c==i)break;
            v.push_back(c);
        }
        int cnt=0;
        for(auto d:v)
        {
            a[d]=mn-v.size()+(++cnt);
        }
        mn-=v.size();
    }
    cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<a[i];
    cout<<endl;
    return 0;
}