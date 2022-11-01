#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1000*1000*1000)
#define N 6
#define ll long long


ll a[N],n[N];
bool four,one;
int main()
{
    
    for(int i=0;i<N;i++)
        cin>>a[i];
        
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(a[i]==a[j])
            n[i]++;
        }
        if(n[i]>=4)
            four=true;
        if(n[i]==1)
            one=true;   
            
    }
    if(four==false)
        cout<<"Alien"<<endl;
    else if(one==true)
        cout<<"Bear"<<endl;
    else
        cout<<"Elephant"<<endl; 
        
            
    
    
        
        
        
        
        
        
        
    
    
    
    return 0;
}