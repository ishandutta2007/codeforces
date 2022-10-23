#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
int n,sl[N],val[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    val[1]=1;
    sl[1]++;
    for (int i=2,x;i<=n;i++)
    {
        cin>>x;
        val[i]=val[x]+1;
        sl[val[i]]++;
    }
    int res=0;
    for (int i=1;i<=n;i++) res+=(sl[i]&1);
    cout<<res;
    return 0;
}