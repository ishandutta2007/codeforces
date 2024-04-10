#include <bits/stdc++.h>
using namespace std;
int N, A[101010], jogun, res=1;
long long ans;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
        if(A[i]==0)
            jogun=1;
    }
    for(int i=0;i<N;i++)
    {
        if(A[i]>0)
            ans+=(long long)A[i]-1;
        else if(A[i]<0)
            ans+=(long long)-1-(long long)A[i], res*=-1;
        else
            ans+=1;
    }
    if(jogun==1)
        cout << ans;
    else
        if(res==-1)
        cout << ans+2;
        else
        cout << ans;
}