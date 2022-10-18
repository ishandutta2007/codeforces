#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    
    cin>>N;
    
    vector<int> c;
    
    c.push_back(N);
    
    int sum=N;
    
    while(c[c.size()-1]!=1)
    {
    if(!(c[c.size()-1]%2))
    {
                          c.push_back(c[c.size()-1]/2);
                          sum+=c[c.size()-1];
    }
    else
                    for(int i=3;;i+=2)       
                    {
                     if(!(c[c.size()-1]%i))
    {
                          c.push_back(c[c.size()-1]/i);
                          sum+=c[c.size()-1];
                          
                          break;
    }       
                    }
    }
    
    cout<<sum<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}