#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n,k;
char a[N];

int t[30];
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>k;
    cin>>a;
    for(int i=0;i<n;++i)
        t[a[i]-'A']++;
    int ans=n;
    for(int i=0;i<k;++i)
        ans=min(ans,t[i]);
    cout<<ans*k<<endl;
    return 0;
}