#include<iostream>
using namespace std;
int main()
{
int m,n,x=1;
cin>>m>>n;
string ev;
string ns;
cin>>ev>>ns;
if (ev[0]==ev[m-1] || ns[0]==ns[n-1] || (ev[0]=='<' && ns[0]=='^') || (ev[0]=='>' && ns[0]=='v'))
    cout<<"NO";
else
    cout<<"YES";
return 0;
}