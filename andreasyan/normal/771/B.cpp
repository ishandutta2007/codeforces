#include <iostream>
#include <string>
#include <set>
using namespace std;
const int N=55;

int k,n;
string a[N];
string ans[N];

int z=0;
int zz=0;
string newname()
{
    string res;
    if(z==26)
    {
        ++zz;
        z=0;
    }
    if(zz==0)
    {
        res+=(z+'A');
    }
    else
    {
        res+=(z+'A');
        res+=(z+'a');
    }
    ++z;
    return res;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<(n-k+1);++i)
        cin>>a[i];
    if(a[0]=="NO")
    {
        ans[0]=newname();
        ans[k-1]=ans[0];
        for(int i=1;i<k-1;++i)
            ans[i]=newname();
    }
    else
    {
        for(int i=0;i<k;++i)
            ans[i]=newname();
    }
    for(int l=1;l<(n-k+1);++l)
    {
        int r=l+k-1;
        if(a[l]=="NO")
        {
            set<string> s;
            for(int i=l;i<r;++i)
                s.insert(ans[i]);
            if(s.size()!=k-1)
                ans[r]=newname();
            else
                ans[r]=ans[l];
        }
        else
        {
            ans[r]=newname();
        }
    }
/////////////////////////////////////
    for(int i=0;i<n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}