////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
pair <int,int> p[5500];
int n,best=-1;
int main()
{
     cin>>n;
     for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
     sort(p,p+n);
     for(int i=0;i<n;i++)
     {
        if(best<=p[i].second)
            best=p[i].second;
        else
            best=p[i].first;    
     }  
     cout<<best<<endl;
     return 0;
}