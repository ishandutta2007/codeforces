#include <iostream>
using namespace std;
#define N (1000*1001)
bool mark[N];
int main()
{
    for(int i=2;i<=N;i++)
        if(mark[i]==false)
            for(int j=2*i;j<=N;j+=i)
                mark[j]=true;
    int n;
    cin>>n;
    for(int i=2;i<=n/2;i++)
        if(mark[i]==true && mark[n-i]==true)
        {
            cout<<i<<" "<<n-i<<endl;
            break;
        }               
    return 0;
}