#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
bool mat[12][12];
int main ()
{

    cin.tie ( 0 )->sync_with_stdio ( 0 );
    cin.tie ( NULL );
    cout.tie ( NULL );
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k==0)
    {
        cout<<s;
        return 0;
    }
    if(n==1)
    {
        cout<<'0';
        return 0;
    }
    if(s[0]!='1')
    {
        s[0]='1';
        k--;
    }
    for(int i=1;i<s.size();i++)
    {
        if(k==0) break;
        if(s[i]!='0')
        {
            k--;
            s[i]='0';
        }
    }
    cout<<s;





}