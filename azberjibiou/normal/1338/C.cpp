#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
typedef long long ll;
using namespace std;
const int mxN=101010;
const int MOD=1000000007;
const ll INF=1000000000000000000;
int A[mxN];
ll po4[1010];
ll pow4[1010];
int jar[3][4]={{0, 3, 1, 2}, {0, 1, 2, 3}, {0, 2, 3, 1}};
ll solv(ll num)
{
    if(num<=3)
    {
        return num;
    }

    ll tur=(num-1)/3+1;
    ll typ=num%3;
    int pos=1;
    while(tur>po4[pos])    pos++;
    int four[100]={};
    int idx=0;
    ll tmp=tur-po4[pos-1]-1;
    while(tmp!=0)
    {
        four[idx++]=tmp%4;
        tmp/=4;
    }
    ll ans=0;
    if(typ==1)
    {
        ans=pow4[pos-1];
    }
    if(typ==2)
    {
        ans=2*pow4[pos-1];
    }
    if(typ==0)
    {
        ans=3*pow4[pos-1];
    }
    for(int i=0;i<idx;i++)
    {
        ans+=pow4[i]*jar[typ][four[i]];
    }
    return ans;
}
int main()
{
    gibon
    po4[1]=1;
    for(int i=2;i<=31;i++)
    {
        po4[i]=4*po4[i-1]+1;
    }
    pow4[0]=1;
    for(int i=1;i<=100;i++)
    {
        pow4[i]=4*pow4[i-1];
    }
    int T;
    cin >> T;
    while(T--)
    {
        ll N;
        cin >> N;
        cout << solv(N) << '\n';
    }
}