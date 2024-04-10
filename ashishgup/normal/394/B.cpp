#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int p, x;
string a, ans;
bool check=0;

void work(int dig)
{
    a.resize(p);
    a[p-1]=dig+'0';
    int carry=0;
    for(int i=p-2;i>=0;i--)
    {
        int prod=(a[i+1]-'0')*x + carry;
        a[i]=(prod%10)+'0';
        carry=prod/10;
    }   
    int curcheck=(((a[0]-'0')*x + carry)==dig && a[0]!='0');
    if(curcheck)
    {
        if(!check)
            ans=a;
        else if(a<ans)
            ans=a;
        check=1;
    }
}
    
int32_t main()
{
    IOS;
    cin>>p>>x;
    for(int dig=1;dig<=9;dig++)
        work(dig);
    if(check)
        cout<<ans;
    else
        cout<<"Impossible";
    return 0;
}