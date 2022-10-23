#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
const int maxn=int(10e5)+1;
int a[maxn],b[maxn];
int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    int n,k,d;
    long long h=0;
    string s;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>s;
    int i=1;
    while (i<=n)
    {
        d=1;
        b[1]=a[i];
        while (i<=n && s[i-1]==s[i])
        {
            i++;
            d++;
            b[d]=a[i];
        }
        sort(b+1,b+d+1);
        for (int j=d;j>=max(1,d-k+1);j--) h=h+b[j];
        i++;
    }
    cout<<h;
    return 0;
}