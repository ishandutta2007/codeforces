#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef struct vec{
    vector <int> v;
}vec;
int N;
long long Ap[101010], ans;
int A[101010][41], idxA;
long long Po2[32];
void Powere()
{
    Po2[0]=1;
    for(int i=1;i<=31;i++)
        Po2[i]=Po2[i-1]*2;
}
long long jag(int idx, vec Con)
{
    int num=Con.v.size();
    if(idx==0)
    {
        int ok1=0, ok0=0;
        for(int i=0;i<num;i++)
        {
            int now=Con.v[i];
            if(A[now][0]==1)   ok1=1;
            if(A[now][0]==0)   ok0=1;
        }
        if(ok1==1 && ok0==1)
            return 1;
        return 0;
    }
    vec V;
    for(int i=0;i<num;i++)
    {
        int now=Con.v[i];
        if(A[now][idx]==1)
            V.v.push_back(now);
    }
    if(V.v.size()==num)
    {
        return jag(idx-1, V);
    }
    long long pre1=jag(idx-1, V);
    V.v.clear();
    for(int i=0;i<num;i++)
    {
        int now=Con.v[i];
        if(A[now][idx]==0)
            V.v.push_back(now);
    }
    if(V.v.size()==num)
        return jag(idx-1, V);
    long long pre2=jag(idx-1, V);
    return min(pre1, pre2)+Po2[idx];
}
int main()
{
    gibon
    Powere();
    cin >> N;
    if(N==1)
    {
        cout << 0;
        return 0;
    }
    for(int i=0;i<N;i++)
        cin >> Ap[i];
    int rN=0;
    for(int i=0;i<N;i++)
    {
        long long tmp=Ap[i];
        int j=0;
        while(tmp!=0)
        {
            A[i][j]=tmp%2;
            tmp/=2;
            j++;
        }
        idxA=max(idxA, j);
    }
    vec Con;
    for(int i=0;i<N;i++)
        Con.v.push_back(i);
    if(idxA==0)
    {
        cout << 0;
        return 0;
    }
    ans=jag(idxA-1, Con);
    cout << ans;
}