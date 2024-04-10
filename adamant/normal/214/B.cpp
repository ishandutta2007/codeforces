#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    
    cin>>n;
    
    vector <int> inp(n);
    
    for(int i=0;i<n;i++)
    {
            cin>>inp[i];
    }
    
    int b=accumulate( inp.begin(), inp.end(),0);
    
    vector<int>::iterator it;
    
    it = find( inp.begin(), inp.end(), 0 );
    
    if(it-inp.begin()==inp.size())
    {
    cout<<-1<<endl;
    return 0;
    }
    
    int a=b%3;
    
    if(a)
    {
         int min=2000000000;
         int iter=0;
     for(int i=0;i<inp.size();i++)    
     {
      if(inp[i]%3==a && inp[i]<min)       
      {
                         min=inp[i];
                         iter=i;   
      }
     }
     if(min != 2000000000)
     {
            inp.erase(inp.begin()+iter);
            goto next;
     }
     
     int min1=2000000000,min2=2000000000;
     int iter1=0,iter2=0;
     for(int i=0;i<inp.size();i++)    
     {
      if( (inp[i]%3!=a) && (inp[i]%3) && (inp[i]<min2) )       
      {
                     if(inp[i]<=min1)
                     {
                         min2=min1;
                         min1=inp[i];
                         iter2=iter1;
                         iter1=i;   
                     }
                     else
                     {
                        min2=inp[i];
                        iter2=i;
                     }
      }
     }
     if(iter2>iter1)
     {
                    int tmp=iter2;
                    iter2=iter1;
                    iter1=tmp;
     }
     if( min2 != 2000000000 )
     {
         inp.erase(inp.begin()+iter1);
         inp.erase(inp.begin()+iter2);
     }
     
    }
    next:
    sort(inp.begin(),inp.end());
    if(!inp[inp.size()-1])
    {
                          cout<<0<<endl;
                          return 0;
    }
    for(int i=inp.size()-1;i>=0;i--)
    cout<<inp[i];
    cout<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}