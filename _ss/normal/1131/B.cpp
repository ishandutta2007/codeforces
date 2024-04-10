#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
int n;
vector<int> a,b;
int main()
{
    cin>>n;
    int x,y;
    a.push_back(0);
    b.push_back(0);
    cin>>x>>y;
    a.push_back(x);
    b.push_back(y);
    for (int i=2;i<=n;i++)
    {
        cin>>x>>y;
        if (a[a.size()-1]==b[b.size()-1])
        {
            a.pop_back();
            b.pop_back();
        }
        a.push_back(x);
        b.push_back(y);
    }
    int d=0;
    for (int i=1;i<a.size();i++) d=d+max(0,(min(a[i],b[i])-max(a[i-1],b[i-1])+1));
    cout<<d;
    return 0;
}