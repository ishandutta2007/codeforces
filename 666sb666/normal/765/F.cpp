#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int inf = 1000000000;
const int limit = 250, maxSize = 100001 / limit + 1;
int minv[limit + 1][100005], t[100005], l1[maxSize], l2[maxSize], a[100005],b[100005],c[100005],last[100005],pos[100005],st[100005][20];
pair<int, int> list[limit][maxSize], all[100005];
inline int Query(int l,int r)
{
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main() {
    int n, q;
    read(n);
    for (int i = 0; i < n; i ++) read(a[i]),b[i+1]=a[i];
    sort(b+1,b+n+1);
    b[0]=unique(b+1,b+n+1)-b-1;
    for (int i=1;i<=n;++i)
        c[i]=lower_bound(b+1,b+b[0]+1,a[i-1])-b;
    for(int i=1;i<=n;i++)last[i]=pos[c[i]],pos[c[i]]=i;
    for(int i=1;i<=n;i++)st[i][0]=last[i];
    for(int j=1;j<=19;j++)
    	for(int i=1;i<=n;i++)if(i+(1<<j)-1<=n)st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    read(q);
    int size = 1, tot;
    while (size * size <= n) size ++;
    size --;
    tot = (n - 1) / size + 1;
    while (tot > limit) {
        size ++;
        tot = (n - 1) / size + 1;
    }
     
    for (int i = 0; i < tot; i ++) {
        int len = min(size, n - i * size);
        for (int j = 0; j < len; j ++)
            list[i][j] = make_pair(a[j + i * size], j + i * size);
        sort(list[i], list[i] + len);
    }
     
    for (int i = 0; i < n; i ++) all[i] = make_pair(a[i], i);
    sort(all, all + n);
     
    for (int i = tot - 1; i >= 0; i --) {
        int l = i * size, r = min(n, (i + 1) * size), len = r - l;
        minv[i][l] = inf;
        set<int> S;
        S.insert(a[l]);
        for (int j = l + 1; j < r; j ++) {
            minv[i][j] = minv[i][j - 1];
            set<int>::iterator p = S.lower_bound(a[j]);
            if (p != S.end()) minv[i][j] = min(minv[i][j], *p - a[j]);
            if (p != S.begin()) {
                p --;
                minv[i][j] = min(minv[i][j], a[j] - *p);
            }
            S.insert(a[j]);
        }
        for (int j = r; j < n; j ++) t[j] = inf;
        for (int j = 0, k = 0; j < len; j ++)
            for ( ; k < n && all[k].first < list[i][j].first; k ++) {
                if (all[k].second < r) continue;
                t[all[k].second] = min(t[all[k].second], list[i][j].first - all[k].first);
            }
        for (int j = len - 1, k = n - 1; j >= 0; j --)
            for ( ; k >= 0 && all[k].first > list[i][j].first; k --) {
                if (all[k].second < r) continue;
                t[all[k].second] = min(t[all[k].second], all[k].first - list[i][j].first);
            }
        for (int j = r; j < n; j ++) {
            minv[i][j] = min(minv[i][j - 1], minv[i + 1][j]);
            minv[i][j] = min(minv[i][j], t[j]);
        }
    }
     
    for (int i = 0; i < tot; i ++) {
        int l = i * size, r = min(n, (i + 1) * size), len = r - l;
        minv[i + 1][r - 1] = inf;
        set<int> S;
        S.insert(a[r - 1]);
        for (int j = r - 2; j >= l; j --) {
            minv[i + 1][j] = minv[i + 1][j + 1];
            set<int>::iterator p = S.lower_bound(a[j]);
            if (p != S.end()) minv[i + 1][j] = min(minv[i + 1][j], *p - a[j]);
            if (p != S.begin()) {
                p --;
                minv[i + 1][j] = min(minv[i + 1][j], a[j] - *p);
            }
            S.insert(a[j]);
        }
        for (int j = 0; j < l; j ++) t[j] = inf;
        for (int j = 0, k = 0; j < len; j ++)
            for ( ; k < n && all[k].first < list[i][j].first; k ++) {
                if (all[k].second >= l) continue;
                t[all[k].second] = min(t[all[k].second], list[i][j].first - all[k].first);
            }
        for (int j = len - 1, k = n - 1; j >= 0; j --)
            for ( ; k >= 0 && all[k].first > list[i][j].first; k --) {
                if (all[k].second >= l) continue;
                t[all[k].second] = min(t[all[k].second], all[k].first - list[i][j].first);
            }
        for (int j = l - 1; j >= 0; j --) {
            minv[i + 1][j] = min(minv[i + 1][j + 1], minv[i][j]);
            minv[i + 1][j] = min(minv[i + 1][j], t[j]);
        }
    }
     
    for ( ; q; q --) {
        int l, r;
        read(l),read(r);
        if(Query(l,r)>=l){puts("0");continue;}
        l --;
        r --;
        int t1 = l / size, t2 = r / size;
        if (t1 == t2) {
            int tot = 0, len = min(size, n - t1 * size);
            for (int i = 0; i < len; i ++)
                if (l <= list[t1][i].second && list[t1][i].second <= r)
                    t[tot ++] = list[t1][i].first;
            int ans = inf;
            for (int i = 0; i < tot - 1; i ++)
                ans = min(ans, t[i + 1] - t[i]);
            write(ans);
            continue;
        }
        int tot1 = 0, len1 = min(size, n - t1 * size);
        for (int i = 0; i < len1; i ++)
            if (l <= list[t1][i].second) l1[tot1 ++] = list[t1][i].first;
        int tot2 = 0, len2 = min(size, n - t2 * size);
        for (int i = 0; i < len2; i ++)
            if (list[t2][i].second <= r) l2[tot2 ++] = list[t2][i].first;
        merge(l1, l1 + tot1, l2, l2 + tot2, t);
        int tot = unique(t, t + tot1 + tot2) - t;
        int ans = inf;
        for (int i = 0; i < tot - 1; i ++)
            ans = min(ans, t[i + 1] - t[i]);
        ans = min(ans, minv[t1 + 1][r]);
        ans = min(ans, minv[t2][l]);
        write(ans);
    }
     
    return 0;
}