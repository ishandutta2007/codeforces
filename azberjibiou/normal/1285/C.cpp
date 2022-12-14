#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef struct sosu{
    long long num, idx;
}sosu;
long long X, a=1, b=1, ans=1000000000000000, ra, rb;
sosu A[1010];
int idxA;
long long B[1010];
void soinsu(long long num)
{
    if(num%2==0)
    {
        A[idxA].num=2;
        while(num%2==0)
        {
            A[idxA].idx++;
            num/=2;
        }
        idxA++;
    }
    for(long long i=3;i*i<=X;i+=2)
    {
        if(num%i==0)
        {
            A[idxA].num=i;
            while(num%i==0)
            {
                A[idxA].idx++;
                num/=i;
            }
            idxA++;
        }
    }
    if(num!=1)
    {
        A[idxA].num=num, A[idxA].idx=1;
        idxA++;
    }
}
void AtoB()
{
    for(int i=0;i<idxA;i++)
    {
        B[i]=1;
        for(int j=0;j<A[i].idx;j++)
        {
            B[i]*=A[i].num;
        }
    }
}
void jag(int idx)
{
    if(idx==idxA)
    {
        long long maks=max(a, b);
        if(ans>maks)
        {
            ra=a, rb=b;
            ans=maks;
        }
        return;
    }
    a*=B[idx];
    jag(idx+1);
    a/=B[idx];
    b*=B[idx];
    jag(idx+1);
    b/=B[idx];
}
int main()
{
    gibon
    cin >> X;
    if(X==1)
    {
        cout << "1 1";
        return 0;
    }
    soinsu(X);
    AtoB();
    jag(0);
    cout << ra << " " << rb;
}