#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define long long long

//Not My Code

int main()
{
    long n,f;
    vector<long> profit;
    long i,j,temp;
    long k,l;
    long sum=0;
    
    profit.clear();
    
    cin>>n>>f;
    
    for(i=0;i<n;i++)
    {
        cin>>k>>l;
        
        if(k>=l) {sum+=l; profit.push_back(0);}
        else if (2*k>=l) { sum+=k; profit.push_back(l-k);}
        else {sum+=k; profit.push_back(k);}
    }
    
    sort(profit.rbegin(),profit.rend());
    
    for(i=0;i<f;i++)
    {
        sum+=profit.at(i);
    }
    
    
    cout<<sum<<endl;
    
    
    
    
    
    
        return 0;
}