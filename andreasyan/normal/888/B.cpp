#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1000006;

int n;
char s[N];

map<pair<int,int>,int> a;

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    cin>>s;
    a[m_p(0,0)]=0;
    for(int i=0;i<n;++i)
    {
        map<pair<int,int>,int> b;
        for(map<pair<int,int>,int>::iterator it=a.begin();it!=a.end();++it)
        {
            pair<int,int> p=it->first;
            b[p]=max(b[p],it->second);
            if(s[i]=='U')
                p.second++;
            else if(s[i]=='D')
                p.second--;
            else if(s[i]=='L')
                p.first--;
            else
                p.first++;
            b[p]=max(b[p],it->second+1);
        }
        a=b;
    }
    cout<<a[m_p(0,0)]<<endl;
    return 0;
}