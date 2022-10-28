#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N];

int32_t main()
{
    IOS;
    cin>>n>>k;
    int min1=n/2;
    if(k<min1 || (n==1 && k>0))
    {
        cout<<"-1";
        return 0;
    }
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    int diff=k - (min1-1);
    set<int> s;
    s.insert(diff);
    s.insert(2*diff);
    cout<<diff<<" "<<2*diff<<" ";
    int ct=0;
    for(int i=1;ct < n/2 - 1; i++)
    {
        if(s.find(i)==s.end() && s.find(i+1)==s.end())
        {
            cout<<i<<" "<<i+1<<" ";
            ct++;
            i++;
        }
    }
    if(n%2)
    {
        cout<<100000001;
    }
    return 0;
}