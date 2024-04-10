#include <bits/stdc++.h>
using namespace std;
vector<bool> a(90,false);

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin>>n;
    for(int i=0,t; i<n; i++)
        cin>>t, a[t-1]=true;

    int s=0;
    for(int i=0; i<15; i++) s+=a[i];

    int ans=15;
    while(ans<90&&s)
    {
        s+=a[ans]-a[ans-15];
        ans++;
    }

    cout<<ans;
    return 0;
}