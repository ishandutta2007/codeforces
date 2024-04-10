#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
char a[N];
char minu[N];

vector<char> t,u;
int main()
{
    int i;
    cin>>a;
    n=strlen(a);
    minu[n]='z';
    for(i=n-1;i>=0;--i)
        minu[i]=min(minu[i+1],a[i]);
    for(i=0;i<n;++i)
    {
        t.push_back(a[i]);
        if(a[i]==minu[0])
            break;
    }
    ++i;
    while(1)
    {
        if(i==n && t.empty())
            break;
        if(i==n)
        {
            u.push_back(t.back());
            t.pop_back();
            continue;
        }
        if(t.empty())
        {
            t.push_back(a[i]);
            ++i;
            continue;
        }
        if(t.back()<=minu[i])
        {
            u.push_back(t.back());
            t.pop_back();
            continue;
        }
        else
        {
            t.push_back(a[i]);
            ++i;
            continue;
        }
    }
    for(int i=0;i<n;++i)
        cout<<u[i];
    cout<<endl;
    return 0;
}