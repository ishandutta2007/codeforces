#include <bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define ll long long
using namespace std;
typedef struct sosu{
    ll num, idx;
}sosu;
sosu A[1010][2];
int idxA[2];
void solv(ll num, int type)
{
    if(num==1)
        return;
    ll tmp=num;
    for(ll i=2;i*i<=num;i++)
    {
        if(tmp%i!=0)
            continue;
        A[idxA[type]][type].num=i;
        A[idxA[type]][type].idx=0;
        while(tmp%i==0)
        {
            tmp/=i;
            A[idxA[type]][type].idx++;
        }
        idxA[type]++;
    }
    if(tmp!=1)
    {
        A[idxA[type]][type].num=tmp, A[idxA[type]][type].idx=1;
        idxA[type]++;
    }
}
int main()
{
    gibon
    int o;
    cin >> o;
    while(o--)
    {
        ll N, M;
        cin >> N >> M;
        idxA[1]=idxA[0]=0;
        solv(N, 0);
        solv(M, 1);
        if(N!=1)
        {
            for(int i=0;i<idxA[1];i++)
            {
                for(int j=0;j<idxA[0];j++)
                {
                    if(A[j][0].num==A[i][1].num)
                    {
                        ll tmp=A[i][1].idx;
                        while(tmp--)
                            M/=A[i][1].num;
                        A[i][1].idx=max((ll)0, A[i][1].idx-A[j][0].idx);
                        tmp=A[i][1].idx;
                        while(tmp--)
                            M*=A[i][1].num;
                        break;
                    }
                }
            }
        }
        ll ans=M;
        for(int i=0;i<idxA[1];i++)
        {
            if(A[i][1].idx>0)
            {
                ans=ans/A[i][1].num*(A[i][1].num-1);
            }
        }
        cout << ans << '\n';
    }
}