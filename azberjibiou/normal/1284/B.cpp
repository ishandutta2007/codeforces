#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef struct stri{
    int big, sma;
}stri;
long long N, total;
bool asc[101010];
stri St[101010];
int sidx;
bool cmp1(stri a, stri b)
{
    return a.big>b.big;
}
int main()
{
    gibon
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int num, A[101010];
        bool jogun=false;;
        cin >> num;
        cin >> A[0];
        for(int j=1;j<num;j++)
        {
            cin >> A[j];
            if(A[j]>A[j-1])
                jogun=true;
        }
        if(jogun==false)
            St[sidx++]={A[0], A[num-1]};
    }
    sort(St, St+sidx, cmp1);
    for(int i=0;i<sidx;i++)
    {
        if(St[i].sma<St[sidx-1].big)
        {
            continue;
        }
        if(St[i].sma>=St[0].big)
        {
            total+=sidx;
            continue;
        }
        int lc=0, rc=sidx-1;
        while(lc!=rc)
        {
            int mid=(lc+rc)/2;
            if(St[mid].big<=St[i].sma)
                rc=mid;
            else
                lc=mid+1;
        }
        total+=sidx-lc;
    }
    cout << (long long)N*N-total;
}