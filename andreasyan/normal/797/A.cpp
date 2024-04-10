#include <bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
    cin>>n>>k;
    vector<int> ans;
    if(ans.size()==(k-1))
    {
        if(n==1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        for(int i=0;i<k-1;++i)
            cout<<ans[i]<<' ';
        cout<<n<<endl;
        return 0;
    }
    for(int i=2;i<=n;++i)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                ans.push_back(i);
                n/=i;
                if(ans.size()==(k-1))
                {
                    if(n==1)
                    {
                        cout<<"-1"<<endl;
                        return 0;
                    }
                    for(int i=0;i<k-1;++i)
                        cout<<ans[i]<<' ';
                    cout<<n<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}