#include <bits/stdc++.h>
using namespace std;
map <string ,long long > use;
string st,st2;
vector <long long > vec;
map<long long ,long long > mp;
long long n,a[1000000],mx,k,ans,step[1000];

int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    step[0]=1;
    for (int i=1;i<=40;i++) step[i]=step[i-1]*2;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=40;j++)
            ans+=mp[step[j]-a[i]];
        mp[a[i]]++;
    }
    cout<<ans;

}