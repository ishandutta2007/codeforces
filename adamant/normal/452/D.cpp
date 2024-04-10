#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,n1,n2,n3,t1,t2,t3;
    cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;

    multiset<int> a,b,c;
    for(int i=0;i<n1;i++) a.insert(0);
    for(int i=0;i<n2;i++) b.insert(0);
    for(int i=0;i<n3;i++) c.insert(0);
    int t;
    for(t=0;k;t++)
    {
        while(k && *a.begin()<=t && *b.begin()<=t+t1 && *c.begin()<=t+t1+t2)
        {
            k--;
            a.erase(a.begin());
            b.erase(b.begin());
            c.erase(c.begin());
            a.insert(t+t1);
            b.insert(t+t1+t2);
            c.insert(t+t1+t2+t3);
        }
    }
    cout<<*--c.end()<<endl;

 }