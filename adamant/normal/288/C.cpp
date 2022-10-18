#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

int main(int argc, char *argv[])
{
    int N;
    cin>>N;
    vector<bool> used(N+1,false);
    vector<int> res(N+1);
    ll sumxor=0;
    int maxN;
    if(N%2==0)
    {
              res[0]=0;
              used[0]=true;
              maxN=N;
    }
    else
    {
        res[N]=0;
        res[0]=N;
        used[N]=true;
        used[0]=true;
        maxN=N-1;
        sumxor+=2*N;
    }
    int maxst2=1;
    while(maxst2<=maxN)
    maxst2*=2;
    maxst2/=2;
int x=0;
    while(maxN>1 && maxst2>1)
    {
     while(used[maxst2] && maxst2>1)
     maxst2/=2;         
               if(maxst2==1)
               continue;
               for(int i=0;i<=maxN-maxst2;++i)
               {
                      used[maxst2+i]=true;
                      used[maxst2-i-1]=true;
                      res[maxst2+i]=maxst2-i-1;
                      res[maxst2-i-1]=maxst2+i;
                      sumxor+=2*((maxst2+i)^(maxst2-i-1));
               }   
               maxN-=(2*(maxN-maxst2+1));
     }
     cout<<sumxor<<endl;
     for(int i=0;i<=N;++i)
     cout<<res[i]<<' ';
     cout<<endl;
     return 0;
}