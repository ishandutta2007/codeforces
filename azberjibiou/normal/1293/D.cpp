#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gibon cin.tie(0); ios::sync_with_stdio(false);
typedef struct pnt{
    ll x, y;
}pnt;
ll x0, y0, ax, ay, bx, by, xs, ys, t;
pnt A[1010];
int idxA=1;
int ans;
ll abss(ll a)
{
    return (a>0 ? a : -a);
}
int main()
{
    gibon
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    A[0].x=x0, A[0].y=y0;
    while(1)
    {
        if(ax*A[idxA-1].x+bx-xs>t || ay*A[idxA-1].y+by-ys>t)    break;
        A[idxA].x=ax*A[idxA-1].x+bx;
        A[idxA].y=ay*A[idxA-1].y+by;
        idxA++;
    }
    for(int i=0;i<idxA;i++)
    {
        ll tmpt=t-abss(A[i].x-xs)-abss(A[i].y-ys);
        if(tmpt<0) continue;
        ll tt=tmpt;
        int idx=i;
        while(idx>0 && tmpt>=abss(A[idx].x-A[idx-1].x)+abss(A[idx].y-A[idx-1].y))
        {
            tmpt-=abss(A[idx].x-A[idx-1].x)+abss(A[idx].y-A[idx-1].y);
            idx--;
        }
        ans=max(ans, i-idx+1);
        idx=i;
        while(idx+1<idxA && tt>=abss(A[idx].x-A[idx+1].x)+abss(A[idx].y-A[idx+1].y))
        {
            tt-=abss(A[idx].x-A[idx+1].x)+abss(A[idx].y-A[idx+1].y);
            idx++;
        }
        ans=max(ans, idx-i+1);
    }
    cout << ans;
}