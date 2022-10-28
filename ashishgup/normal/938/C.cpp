#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, m, x;
set<int> s;

int checksq(int k)
{
    int temp=sqrt(k);
    for(int i=temp-2;i<=temp+2;i++)
        if(i*i == k)
            return 1;
    return 0;
}

vector<int> factorise(int k)
{
    vector<int> v;
    for(int i=1;i*i<=k;i++)
    {
        if(k%i==0)
        {
            v.push_back(i);
            v.push_back(k/i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(x==0)
        {
            cout<<"1 1"<<endl;
            continue;
        }
        vector<int> v=factorise(x);
        int flag=0;
        for(int i=0, j=v.size()-1;i<j;i++, j--)
        {
            int k1=v[j];
            int k2=v[i];
            if((k1+k2)%2!=0)
                continue;
            int a=(k1+k2)/2;
            int b=(k1-k2)/2;
            if(b==0)
            	continue;
            int n=a;
            int m=n/b;
            int lhs=n*n - (n/m) * (n/m);
            int rhs=x;
            if(lhs!=rhs)
                continue;
            cout<<n<<" "<<m<<endl;
            flag=1;
            break;
        }
        if(!flag)
            cout<<"-1"<<endl;
    }
    return 0;
}