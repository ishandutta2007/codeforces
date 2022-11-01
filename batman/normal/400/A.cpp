#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define N 
#define ll long long
/*
OXXXOXOOXOOX


*/
int main()
{
    int t,a[6]={12,6,4,3,2,1};
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int ans=0,ans1[6]={};
        string s="";
        cin>>s;
        for(int j=0;j<6;j++)
            for(int c=0;c<a[j];c++)
            {
                int p=0;
                for(int k=c;k<12;k+=a[j])
                    if(s[k]=='X')
                        p++;
                if(p==12/a[j])
                {
                    ans1[ans]=a[j];
                    ans++;
                    break;
                }
                            
            }
        cout<<ans<<" ";
        for(int j=0;j<ans;j++)
            cout<<12/ans1[j]<<"x"<<ans1[j]<<" ";
        cout<<endl; 
    }   
    return 0;
}