#include <bits/stdc++.h>
using namespace std;
pair <long long,long long> p[8],q[8];
long long ex[10];
ifstream fin("input.txt");
int main()
{ 
    for(int i=0;i<8;i++)
    {
        cin>>p[i].first>>p[i].second;
        q[i].first=p[i].second;
        q[i].second=p[i].first;
    }
        
    sort(p,p+8);
    if((p[0].first != p[1].first) || (p[1].first != p[2].first) || (p[3].first != p[4].first) || (p[5].first != p[6].first) || (p[6].first != p[7].first) || (p[0].first >= p[3].first) || (p[3].first)>=p[7].first)
    {
        cout<<"ugly";
        return 0;
    }   
    sort(q,q+8);
    if((q[0].first != q[1].first) || (q[1].first != q[2].first) || (q[3].first != q[4].first) || (q[5].first != q[6].first) || (q[6].first != q[7].first) || (q[0].first >= q[3].first) || (q[3].first)>=q[7].first)
    {
        cout<<"ugly";
        return 0;
    }
    if((p[0].second == p[1].second) || (p[1].second == p[2].second))
    {
        cout<<"ugly";
        return 0;
    }
    if((q[0].second == q[1].second) || (q[1].second == q[2].second))
    {
        cout<<"ugly";
        return 0;
    }
    long long x[3]={q[0].second,q[1].second,q[2].second},y[3]={p[0].second,p[1].second,p[2].second},pp=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(i!=1 || j!=1)
                for(int k=0;k<8;k++)
                    if(x[i]==p[k].first && y[j]==p[k].second)
                    {
                        pp++;
                        break;
                    }
    if(pp!=8)
    {
        cout<<"ugly";
        return 0;
    }
    cout<<"respectable";
    return 0;
}