#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int N, K;
char Ap[2020][30];
int A[2020][30];
long long Has[2020], Po3[32], ans;
multiset <long long> s;
long long hashing(int now)
{
    long long preans=0;
    for(int i=0;i<K;i++)
    {
        preans+=Po3[i]*A[now][i];
    }
    return preans;
}
void Powere()
{
    Po3[0]=1;
    for(int i=1;i<31;i++)
        Po3[i]=Po3[i-1]*3;
}
int main()
{
    gibon
    cin >> N >> K;
    Powere();
    for(int i=0;i<N;i++)
    {
        cin >> Ap[i];
        for(int j=0;j<K;j++)
        {
            if(Ap[i][j]=='S')
                A[i][j]=0;
            else if(Ap[i][j]=='E')
                A[i][j]=1;
            else
                A[i][j]=2;
        }
    }
    for(int i=0;i<N;i++)
    {
        Has[i]=hashing(i);
        s.insert(Has[i]);
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
                continue;
            long long a1=Has[i], a2=Has[j];
            for(int k=0;k<K;k++)
            {
                A[2013][k]=(9-A[i][k]-A[j][k])%3;
            }
            long long b=hashing(2013);
            s.erase(s.find(a1));
            s.erase(s.find(a2));
            ans+=s.count(b);
            s.insert(a1);
            s.insert(a2);
        }
    }
    cout << ans/6;
}