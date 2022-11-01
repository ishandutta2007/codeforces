#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define sz(a) ((int) a.size())
#define ff first
#define ss second
using namespace std;

struct tup {
    int v, ii, jj;
};

tup mt (int v, int ii, int jj) {
    tup temp;
    temp.v = v;
    temp.ii = ii;
    temp.jj = jj;
    return temp;
}

bool cmp(tup fs, tup sc){ return fs.v<sc.v; }

int main()
{
    int n, m;
    scanf_s("%d%d", &n, &m);
    vector<vector<int> > t(n);
    for(int i=0; i<n; i++) t[i].resize(m);
    vector<tup> q;
    for(int i=0, u; i<n; i++) for(int j=0; j<m; j++) scanf_s("%d", &u), q.pb(mt(u,i,j));
    sort(q.begin(), q.end(), &cmp);
    vector<pair<int,int> > nn(n, mp(0, 0)), mm(m, mp(0, 0));
    for(int i=0, sz=n*m; i<sz; i++)
    {
        int j;
        for(j=i; j<sz && q[i].v==q[j].v; j++) {}
        j--;
        for(int o=0; o<20; o++)
            for(int k=i; k<=j; k++)
            {
                int v=q[k].v, ii=q[k].ii, jj=q[k].jj;
                int v1 = nn[ii].ss + (v != nn[ii].ff);
                int v2 = mm[jj].ss + (v != mm[jj].ff);
                int mv = max(v1, v2);
                nn[ii] = max(nn[ii], mp(v, mv));
                mm[jj] = max(mm[jj], mp(v, mv));
            }
        for(int k=i; k<=j; k++)
            t[q[k].ii][q[k].jj] = max(nn[q[k].ii].ss, mm[q[k].jj].ss);
        i=j;
    }
    for(int i=0; i<n; i++, printf("\n"))
        for(int j=0; j<m; j++)
            printf("%d ", t[i][j]);
    return 0;
}