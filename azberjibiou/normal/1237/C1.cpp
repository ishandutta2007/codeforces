/*#include <bits/stdc++.h>
using namespace std;
#define gibon ios::sync_with_stdio(false); cin.tie(0);
typedef struct{
    int str, fin, val;
}node;
int N;
node bseg[401010], sseg[401010];
void input()
{
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> A[i];
}
void initseg(int idx, int star, int fini)
{
    bseg[idx].str=sseg[idx].str=star;
    bseg[idx].fin=sseg[idx].fin==fini;
    if(star==fini)
        return;
    int mid=(star+fini)/2;
    initseg(2*idx, star, mid);
    initseg(2*idx+1, mid+1, fini);
}
void upd(int idx, int num, int pos)
{
    if(num<sseg[idx].val)
        sseg[idx].val=num;
    if(num>bseg[idx].val)
        bseg[idx].val=num;
    if(sseg[idx].str==sseg[idx].fin)
        return;
    int mid=(sseg[idx].str+sseg[idx].fin)/2;
    if(pos<=mid)
        upd(2*idx, num, pos);
    else
        upd(2*idx+1, num, pos);
}
int dping(int pos)
{
    if(findbig(pos+1, N-1)<A[pos])
}
int main()
{
    gibon
    input();
    for(int i=0;i<N;i++)
    {
        upd(1, A[i], i);
    }
    initseg(0, 0, N-1);
    for(int i=0;i<N;i++)
        cout << dping(i) << " ";
}*/
#include <bits/stdc++.h>
using namespace std;
int N;
typedef struct point{
    int x, y, z;
}point;
point A[2020];
bool chk[2020];
int dist(int a, int b)
{
    return abs(A[a].x-A[b].x)+abs(A[a].y-A[b].y)+abs(A[a].z-A[b].z);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> A[i].x >> A[i].y >> A[i].z;
    for(int i=0;i<N;i++)
    {
        int here=i;
        int big=1000000007;
        int pos=i;
        if(chk[here])
            continue;
        for(int j=0;j<N;j++)
        {
            if(!chk[j] && j!=i)
            {
                if(dist(i, j)<big)
                {
                    big=dist(i, j);
                    pos=j;
                }
            }
        }
        cout << here+1 << " " << pos+1 << '\n';
        chk[here]=chk[pos]=true;
    }
}