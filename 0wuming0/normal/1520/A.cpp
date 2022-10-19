#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int n;
        cin>>n;
        char c=-1;
        set<char>s;
        int num=0;
        for(int i=0;i<n;i++)
        {
            char t;
            cin>>t;
            if(t!=c)
            {
                c=t;
                num++;
                s.insert(t);
            }
        }
        if(s.size()==num)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}