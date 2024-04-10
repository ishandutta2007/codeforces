#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> prost;

int main(int argc, char *argv[])
{
    int N;
    
    cin>>N;
    
    vector<int> c;
    
    c.push_back(N);
    
    int sum=N;
    
    prost.push_back(2);
    
    for(int i=3;i<=sqrt(N);i+=2)
    {
            //cout<<"ok"<<endl;
            bool ok=true;
            int t=sqrt(i);
            for(int j=0;j<prost.size() && ok && prost[j]<=t;j++)
            if(!(i%prost[j]))
            ok=false;
            if(ok)
            prost.push_back(i);
            
    }
    
    while(c[c.size()-1]!=1)
    {
                           bool found=false;
                    for(int i=0;i<prost.size();i++)       
                    {
                     if(prost[i]>c[c.size()-1])       
                     break;
                     if(!(c[c.size()-1]%prost[i]))
    {
                     
                     found=true;
                     
                          c.push_back(c[c.size()-1]/prost[i]);
                          sum+=c[c.size()-1];
                          
                          break;
    }       
                    }
                    
                    if(!(found))
                    {
                    sum++;
                    break;
                    }
                    
    }
    
    cout<<sum<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}