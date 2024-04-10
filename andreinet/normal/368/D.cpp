#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

const int N=200005;

unordered_map <int, int> h;
vector <int> c[N], sol;

int modul(int k)
{
    if(k<0) return -k;
    return k;
}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, i, j, p, x, ss=0, s;
    vector <int>::iterator it;
    scanf("%d%d%d", &n, &m, &p);
    for(i=0;i<n;i++)
    {
        scanf("%d", &x);
        c[i%p].push_back(x);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d", &x);
        h[x]++;
        ss++;
    }
    for(x=0;x<p;x++)
    {
        if(c[x].size()<m) continue;
        unordered_map <int, int> l=h;
        j=0; s=ss;
        for(i=0;i<c[x].size();i++)
        {
            s-=modul(l[c[x][i]]);
            l[c[x][i]]--;
            s+=modul(l[c[x][i]]);
            if(i>=m)
            {
                s-=modul(l[c[x][i-m]]);
                l[c[x][i-m]]++;
                s+=modul(l[c[x][i-m]]);
            }
            if(!s)
            {
                sol.push_back(x+(i-m+1)*p);
            }
        }
    }
    sort(sol.begin(), sol.end());
    printf("%d\n", sol.size());
    for(it=sol.begin();it!=sol.end();it++)
    {
        printf("%d ", *it+1);
    }
}