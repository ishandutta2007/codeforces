#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e6+10;
vector<char> a,b;
//string a,b;
int main()
{
    //scanf("%s",&a);
    //scanf("%s",&b);
    char c=getchar();
    while (c!=-1 && c!='\n')
    {
        a.pb(c);
        c=getchar();
    }
    c=getchar();
    while (c!=-1 && c!='\n')
    {
        b.pb(c);
        c=getchar();
    }
    int d=0;
    for (int i=0;i<b.size()-1;i++)
        if (b[i]!=b[i+1]) d^=1;
    int cnt=0,k=0;
    for (int i=0;i<b.size();i++)
        if (a[i]!=b[i]) k^=1;
    if (!k) cnt++;
    for (int i=b.size();i<a.size();i++)
    {
        k^=d;
        k^=(a[i]!=b[b.size()-1]);
        k^=(a[i-b.size()]!=b[0]);
        if (!k) cnt++;
    }
    cout<<cnt;
    return 0;
}