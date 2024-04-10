#include"bits/stdc++.h"
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int num1=0,num2=0;
        vector<int>u,v;
        vector<int>::iterator it1,it2;
        for(int i=30;i>=0;i--)
        {
            if(n&(1<<i))u.push_back(i);
            if(m&(1<<i))v.push_back(i);
        }
        it1=u.begin();
        it2=v.begin();
        while(it2!=v.end())
        {
            if(it1==u.end())
            {
                cout<<"no"<<endl;
                goto ne;
            }

            if(*it1>*it2)
            {
                it1++;
                continue;
            }
            it1++;
            it2++;
        }
        if(n<=m)
            cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        ne:;
    }
    return 0;
}
/*
10
6 9
1 9
7 8
5 4
7 9
*/