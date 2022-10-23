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
char s[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    int n=strlen(s+1),res=0;
    for (int i=1;i<n;i++)
    {
        int l=0,r=0;
        for (int j=i;j<=n;j++)
        {
            if (s[j]=='(') l++,r++;
            else if (s[j]==')') l--,r--;
            else l--,r++;
            while (l<0) l+=2;
            if (l>r) break;
            if (((j-i)&1) && l<=0) res++;
        }
    }
    cout<<res;
    return 0;
}