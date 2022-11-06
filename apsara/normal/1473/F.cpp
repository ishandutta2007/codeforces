#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V=3100;
const int En=V * 200;
const int oo=0x3f3f3f3f;
struct Edge{int num,ne,c;}e[En];
int d[V],p[V],pre[V],low[V];
int gap[V],cur[V];
int N,K,st,ed;
void add(int x,int y,int c)
{
	e[K].num=y;e[K].c=c;
	e[K].ne=p[x];p[x]=K++;
	e[K].num=x;e[K].c=0;
	e[K].ne=p[y];p[y]=K++;
}
int sap()
{
	int ret=0;
	bool fail;
	for(int i=0;i<=N;i++)
	{
		low[i]=gap[i]=d[i]=0;
		cur[i]=p[i];
	}
	low[st]=oo;gap[0]=N;int u=st;
	while(d[st]<N)
	{
		fail=true;
		for(int i=cur[u];i!=-1;i=e[i].ne)
		{
			int v=e[i].num;cur[u]=i;
			if(e[i].c&&d[u]==d[v]+1)
			{
				pre[v]=i;
				low[v]=min(low[u],e[i].c);u=v;
				if(u==ed)
				{
					do
					{
						e[pre[u]].c-=low[ed];
						e[pre[u]^1].c+=low[ed];
						u=e[pre[u]^1].num;
					}while(u!=st);
					ret+=low[ed];
				}
				fail=false;break;
			}
		}
		if(fail)
		{
			gap[d[u]]--;
			if(!gap[d[u]])return ret;
			d[u]=N;
			for(int i=p[u];i!=-1;i=e[i].ne)
			if(e[i].c)d[u]=min(d[u],d[e[i].num]+1);
			gap[d[u]]++;cur[u]=p[u];
			if(u!=st)u=e[pre[u]^1].num;
		}
	}
	return ret;
}

const int M = 100;
int a[V], b[V], n, last[V];
int main() {
    while (~scanf("%d", &n)) {
        N = n + 2;
        st = 0, ed = N - 1;
        for (int i = 0; i < N; ++i) p[i] = -1; K = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        for (int i = 1; i <= M; ++i) last[i] = -1;
        int s = 0;
        for (int i = n; i > 0; --i) {
            if (b[i] > 0) s += b[i], add(st, i, b[i]);
            else add(i, ed, -b[i]);
            for (int j = a[i]; j <= M; j += a[i]) {
                if (last[j] != -1) add(last[j], i, oo);
            }
            last[a[i]] = i;
        }
        printf("%d\n", s - sap());
    }
    return 0;
}

/*
9
4 7 3 4 5 6 7 8 13
-2 3 -19 5 -6 7 -8 9 1

2
42 42
-37 13

2
42 42
13 -37
*/