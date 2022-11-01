#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b||(c!=0&&(b-a)%c==0)&&1ll*(b-a)*c>=0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}