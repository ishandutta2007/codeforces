#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    while(t>0)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]<s[i+1])
            {
                char temp=s[i+1];
                s[i+1]=s[i];
                s[i]=temp;
                i++;
            }
        }
        t--;
    }
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
    }
    return 0;
}