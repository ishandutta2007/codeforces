#include <bits/stdc++.h>
using namespace std;
typedef struct pii{
    long long num, gasu;
}pii;
long long N, I, A[401010], idx, Pow2[41], pos, Sum[401010];
int ans;
pii B[401010];
void pow2()
{
    Pow2[0]=1;
    for(int i=1;i<=30;i++)
    {
        Pow2[i]=Pow2[i-1]*2;
    }
}
int main()
{
    pow2();
    cin >> N >> I;
    for(int i=0;i<N;i++)
        cin >> A[i];
    sort(A, A+N);
    B[0].num=A[0], B[0].gasu=1;
    for(int i=1;i<N;i++)
    {
        if(A[i]==A[i-1])
            B[idx].gasu++;
        else
        {
            idx++;
            B[idx].num=A[i];
            B[idx].gasu=1;
        }
    }
    idx++;
    pos=8*I/N;
    if(pos>18)
        ans=0;
    else
    {
        pos=Pow2[pos];
        for(int i=0;i<pos;i++)
            Sum[0]+=B[i].gasu;
        ans=Sum[0];
        for(int i=1;i+pos-1<idx;i++)
        {
            Sum[i]=Sum[i-1]+B[i+pos-1].gasu-B[i-1].gasu;
            if(ans<Sum[i])
                ans=Sum[i];
        }
        ans=N-ans;
    }
    cout << ans;
}