#include <bits/stdc++.h>

using namespace std;

long long area(int a,int b,int c)
{
    printf("1 %d %d %d\n",a,b,c);
    fflush(stdout);
    long long t;
    scanf("%I64d",&t);
    return t;
}

bool cc(int a,int b,int c)
{
    printf("2 %d %d %d\n",a,b,c);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return (t==1);
}

int main()
{
    int n;
    scanf("%d",&n);
    int one=1;
    int two=2;
    for(int i=3;i<=n;i++) if(cc(one,two,i)==0) two=i;
    vector<pair<long long,int>> v;
    for(int i=2;i<=n;i++)
    {
        if(i==two) continue;
        v.push_back({area(one,two,i),i});
    }
    sort(v.begin(),v.end(),greater<pair<long long,int>>());
    vector<int> a,b;
    a.push_back(v[0].second);
    for(int i=1;i<n-2;i++)
    {
        if(cc(one,v[0].second,v[i].second)) a.push_back(v[i].second);
        else b.push_back(v[i].second);
    }
    reverse(b.begin(),b.end());
    vector<int> res={one,two};
    for(int t:b) res.push_back(t);
    for(int t:a) res.push_back(t);
    printf("0 ");
    for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    fflush(stdout);
    return 0;
}