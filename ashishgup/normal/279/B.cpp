#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{ 
    
        ll n,t;
        cin>>n>>t;
        vector<int> v(n);
        vector<int> v2(n);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            sum+=v[i];
            v2[i]=sum;
        }
        long long max=0;
        long long books=0;
        for(int i=0;i<n;i++)
        {
            books=upper_bound(v2.begin(),v2.end(),t)-v2.begin()-i;
            if(books>max)
            {
                max=books;
            }
            t=t+v[i];
        }
        cout<<max<<endl;
    
    
    
    return 0;
}