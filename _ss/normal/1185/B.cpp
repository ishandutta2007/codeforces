#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e6+1;
string a,b;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        //scanf("%s %s",&a,&b);
        cin>>a>>b;
        a=a+' ';
        b=b+' ';
        int t2=0,kt=1,d=1,d2;
        for (int t=0;t<a.length()-1;t++)
            if (a[t]==a[t+1]) d++;
            else
            {
                if (b[t2]!=a[t]) kt=0;
                d2=1;
                while (t2<b.length()-1 && b[t2]==b[t2+1]) t2++,d2++;
                t2++;
                if (d2<d) kt=0;
                d=1;
            }
        if (b[t2]!=' ') kt=0;
        if (kt) cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
    return 0;
}