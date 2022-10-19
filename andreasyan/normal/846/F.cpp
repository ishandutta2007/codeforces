#include <bits/stdc++.h>
using namespace std;
const int N=1000006;

long long n;
int a[N];

vector<int> b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        int p;
        if(b[a[i]].empty())
            p=0;
        else
            p=b[a[i]].back();
        b[a[i]].push_back(i);
        ans+=((n-i+1)*(i-p)*2-1);
    }
    cout<<(ans+0.0)/(n*n)<<endl;
    return 0;
}