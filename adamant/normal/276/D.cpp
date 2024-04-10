#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
 
using namespace std;
 
#define ll long long
 
string lltoa(ll a)
{
string ret;
while(a)
{
ret.push_back(a%2+'0');
a/=2;
}
reverse(ret.begin(),ret.end());
return ret;
}

int main(int argc, char *argv[])
{
    ll l,r;
    cin>>l>>r;
    
    string a=lltoa(l);
    string b=lltoa(r);
string ans(b.size(),'0');
int st;
bool ok=false;
if(a.size()<b.size())
st=0,ok=true;
else
st=1;
for(int i=st;i<b.size();i++)
if(ok)
ans[i]='1';
else if((a[i]=='0' && b[i]=='1') || (b[i]=='0' && a[i]=='1'))
ok=true,ans[i]='1';
else
ans[i]='0';


    cout<<stoll(ans,NULL,2)<<endl;
    return EXIT_SUCCESS;
}