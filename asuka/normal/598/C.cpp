#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<long double,int> > K;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long double x,y;cin>>x>>y;
        pair<long double,int> KK;
        KK.first = atan2(y,x),KK.second = i+1;
        K.push_back(KK);
    }
    sort(K.begin(),K.end());
    long double ans1 = 2*acos(-1.0);
    int ans2 = 0,ans3 = 0;
    for(int i=0;i<n;i++)
    {
        long double t = (K[(i+1)%n].first-K[i].first);
        if(t<0)t+=acos(-1.0)*2;
        if(t<ans1)
        {
            ans1 = t;
            ans2 = K[i].second;
            ans3 = K[(i+1)%n].second;
        }
    }
    printf("%d %d",ans2,ans3);
}