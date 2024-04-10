#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=14;

int n,m;
pair<int,int> a[N],b[N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        if(a[i].first>a[i].second)
            swap(a[i].first,a[i].second);
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i].first>>b[i].second;
        if(b[i].first>b[i].second)
            swap(b[i].first,b[i].second);
    }
    vector<pair<int,int> > hnaravor;
    set<int> qa[N],qb[N];
    set<int> s;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i]==b[j])
                continue;
            if(a[i].first==b[j].first)
            {
                hnaravor.push_back(m_p(i,j));
                qa[i].insert(a[i].first);
                qb[j].insert(a[i].first);
                s.insert(a[i].first);
            }
            if(a[i].first==b[j].second)
            {
                hnaravor.push_back(m_p(i,j));
                qa[i].insert(a[i].first);
                qb[j].insert(a[i].first);
                s.insert(a[i].first);
            }
            if(a[i].second==b[j].first)
            {
                hnaravor.push_back(m_p(i,j));
                qa[i].insert(a[i].second);
                qb[j].insert(a[i].second);
                s.insert(a[i].second);
            }
            if(a[i].second==b[j].second)
            {
                hnaravor.push_back(m_p(i,j));
                qa[i].insert(a[i].second);
                qb[j].insert(a[i].second);
                s.insert(a[i].second);
            }
        }
    }
    if(s.size()==1)
    {
        int i=hnaravor[0].first;
        int j=hnaravor[0].second;
        cout<<(*s.begin())<<endl;
        return 0;
    }
    bool za=true;
    for(int i=0;i<n;++i)
        if(qa[i].size()>1)
        {
            za=false;
            break;
        }
    bool zb=true;
    for(int i=0;i<m;++i)
        if(qb[i].size()>1)
        {
            zb=false;
            break;
        }
    if(!za || !zb)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<"0"<<endl;
    return 0;
}