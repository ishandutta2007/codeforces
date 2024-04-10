#include <algorithm>
#include <cstdio>
#include <queue>
#define PII pair<int, pair<int, int>>
#define x first
#define y second.first
#define z second.second

using namespace std;

const int N=100005;

PII a[N], b[N];
int c[N], soli[N];
int n, m, s;

bool verif(int nr)
{
    int i, j=n, cost=0, k;
    priority_queue <PII, vector<PII>, greater<PII>> q;
    c[0]=0;
    for(i=m;i>0;i-=nr)
    {
        for(;j&&a[j].x>=b[i].x;j--) q.push(make_pair(a[j].y, make_pair(a[j].z, 0)));
        if(!q.empty())
        {
            cost+=q.top().x;
            for(k=i;i-k<nr&&k>0;k--) c[b[k].y]=q.top().y;
            q.pop();
            if(cost>s) return 0;
        }
        else return 0;
    }
    return 1;
}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int i, sol=-1, st, dr, mij;
    scanf("%d%d%d", &n, &m, &s);
    for(i=1;i<=m;i++)
    {
        scanf("%d", &b[i].x);
        b[i].y=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i].x);
        a[i].z=i;
    }
    for(i=1;i<=n;i++) scanf("%d", &a[i].y);
    sort(b+1, b+m+1);
    sort(a+1, a+n+1);
    st=1;
    dr=m;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(verif(mij))
        {
            dr=mij-1;
            sol=mij;
            for(i=1;i<=m;i++) soli[i]=c[i];
        }
        else st=mij+1;
    }
    if(sol==-1) printf("NO");
    else
    {
        printf("YES\n");
        for(i=1;i<=m;i++) printf("%d ", soli[i]);
    }
}