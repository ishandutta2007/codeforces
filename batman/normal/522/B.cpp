#include <bits/stdc++.h>
using namespace std;
#define N (300*1001)
int n,maxh[2],sumw,w[N],h[N];
int main()
{ 
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>h[i];
        sumw+=w[i];
        if(h[i]>maxh[0])
            maxh[1]=maxh[0],maxh[0]=h[i];
        else if(h[i]>maxh[1])
            maxh[1]=h[i];
    }
    for(int i=0;i<n;i++)
        cout<<(sumw-w[i])*((h[i]!=maxh[0])?maxh[0]:maxh[1])<<" ";
    return 0;
}