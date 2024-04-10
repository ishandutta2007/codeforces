#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
int a[100];
int main()
{
    int n;
    cin>>n;
    char ch=getchar();
    for (int i=1;i<=n;i++)
    {
        ch=getchar();
        if (ch=='L')
        {
            for (int i=0;i<=9;i++)
                if (!a[i])
            {
                a[i]=1;
                break;
            }
        }
        else if (ch=='R')
        {
            for (int i=9;i>=0;i--)
                if (!a[i])
            {
                a[i]=1;
                break;
            }
        }
        else a[ch-'0']=0;
    }
    for (int i=0;i<=9;i++) cout<<a[i];
    return 0;
}