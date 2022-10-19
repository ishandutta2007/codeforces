#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int a[N];

int first1[N],first2[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(!first1[a[i]])
            first1[a[i]]=i;
    }
    for(int i=n;i>=1;--i)
    {
        if(!first2[a[i]])
            first2[a[i]]=i;
    }
    vector<int> v1,v2;
    for(int i=1;i<N;++i)
        if(first1[i])
            v1.push_back(first1[i]);
    for(int i=1;i<N;++i)
        if(first2[i])
            v2.push_back(first2[i]);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int j=0;
    long long ans=0;
    for(int i=0;i<v1.size();++i)
    {
        int x=v1[i];
        while(j<v2.size() && v2[j]<=x)
            ++j;
        ans+=(v2.size()-j);
    }
    cout<<ans<<endl;
    return 0;
}