#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e6+10;
char a[N];
int n;
int main()
{
    //freopen("ss.inp","r",stdin);
    scanf("%d",&n);
    scanf("%s",(a+1));;
    int res=0,d=0;
    for (int i=1;i<=n;i++)
    {
        if (d==-1 && a[i]=='(') res++;
        if (a[i]=='(') d++;
        else d--;
        if (d<0) res++;
    }
    if (d!=0) cout<<-1;
    else cout<<res;
    return 0;
}