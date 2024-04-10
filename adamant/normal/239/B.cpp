#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    int l;
    int r;
    
    for(int i=0;i<q;i++)
    {
    cin>>l>>r;
    int ans[10]={0,0,0,0,0,0,0,0,0,0};
    string tmp=s.substr(l-1,r-l+1);
    int CP=0,DP=1;
    while(tmp.size() && (CP>=0 && CP<tmp.size()))
    {
                     if(tmp[CP]>='0' && tmp[CP]<='9')
                     {
                           ans[tmp[CP]-'0']++;
                           tmp[CP]--;
                           if(tmp[CP]<'0')      
                           {    
                           tmp.erase(tmp.begin()+CP,tmp.begin()+CP+1);
                           if(DP)
                           CP--;
                           }
                     if(DP)
                     {
                           CP++;
                     }
                     else
                     {
                         CP--;
                     }
                     }
                     else
                     {
                         if(tmp[CP]=='>')
                         {
                                         CP++;
                                          if(CP>tmp.size()-1)
                                          break;
                                         if(!(tmp[CP]>='0' && tmp[CP]<='9'))
                                         {
                                         tmp.erase(tmp.begin()+CP-1,tmp.begin()+CP);
                                         CP--;
                                         }
                                         DP=1;
                                         //cout<<tmp<<endl; 
                         }
                         else
                         {
                                         CP--;
                                         if(CP<0)
                                         break;

                                         if(!(tmp[CP]>='0' && tmp[CP]<='9'))
                                         {
                                         tmp.erase(tmp.begin()+CP+1,tmp.begin()+CP+2);
                                         }
                                         //cout<<tmp<<endl;  
                                         DP=0;                         
                         }
                     }
    }
    for(int k=0;k<10;k++)
    cout<<ans[k]<<' ';
    
    cout<<endl;
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}