#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long calc(long long x,int t)
{
    long long sum=0;
    for (;;)
    {
        x/=t;
        sum+=x;
        if (x==0) return sum;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    long long a,b;
    cin>>b>>a;
    long long t1=calc(a,2)-calc(b,2);
    long long t2=calc(a,5)-calc(b,5);
    if ((t1>=1)&&(t2>=1))
    {
        puts("0");
    }
    else if (t2>=1)
    {
        puts("5");
    }
    else
    {
        //t2=0!
        long long p=1;
        long long i;
        for (i=b+1;i<=a;i++)
        {
            p=p*i%10;
        }
        cout<<p<<endl;
    }
    return 0;
}