#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string st[10000];
bool check;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
        if (st[i][0]==st[i][1] && st[i][0]=='O' && check==0)
        {
            check=1;
            st[i][0]='+';
            st[i][1]='+';
        }
        if (st[i][3]==st[i][4] && st[i][3]=='O' && check==0)
        {
            check=1;
            st[i][3]='+';
            st[i][4]='+';
        }
    }
    if (check)
    {

        cout<<"YES"<<'\n';
        for (int i=1;i<=n;i++)
            cout<<st[i]<<'\n';
        }else cout<<"NO";

}