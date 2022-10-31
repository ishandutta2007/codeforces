#include <bits/stdc++.h>
using namespace std;
long long n,a[200*1000],ans;
vector <long long> v;
ifstream fin("input.txt");
int main()
{ 
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=29;i>=0;i--)
    {
        
        //cerr<<(1<<i)<<endl;
        for(int j=0;j<n;j++)
            if((a[j] & (1<<i))==(1<<i))
                v.push_back(a[j]);
            
                        
        bool mark=0;
        for(int k=i-1;k>=0;k--)
        {
            int num=0;
            for(int j=0;j<v.size();j++)
                if((v[j] & (1<<k))==(1<<k))
                    num++;
            if(num==v.size())
            {
                mark=1;
                break;
            }       
        }
        if(v.size()==1 && (v[0] & (1<<i)!=(1<<i)))
            mark=1;
        
        if(!mark)
        {
            cout<<v.size()<<endl;
            for(int j=0;j<v.size();j++)
                    cout<<v[j]<<" ";
            return 0;       
        }
        v.clear();
            
    }                   
    return 0;
}