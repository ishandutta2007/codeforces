#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e2+1;
int n,a[maxn];
int main()
{
    cin>>n;
    char chh=getchar();
    for (int i=1;i<=n;i++) a[i]=(int)(getchar()-'0');
    int s=0,st,kt;
    for (int i=1;i<n;i++)
    {
        s+=a[i];
        st=0;
        kt=1;
        for (int j=i+1;j<=n;j++)
        {
            if (st==s && a[j]) st=0;
            st+=a[j];
            if (st>s) {kt=0;break;}
        }
        if (kt==1 && st==s)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}