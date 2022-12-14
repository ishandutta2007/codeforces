#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
char stri[202020];
int N, M, pref[202020], one;
int gasu[60606060];
long long total;
vector <int> idx_one;
long long solve(int lstr, int lfin, int rstr, int rfin, int sub)
{
    long long preans=0;
    for(int i=lstr;i<=lfin;i++)
    {
        if(i+sub*(M+1)>rfin)
            continue;
        if(i+sub*(M+1)>=rstr)
        {
            preans+=(rfin-i-sub*M)/sub;
        }
        else if(i+sub*(M+1)<=rfin)
        {
            preans+=(rfin-i)/sub;
            preans-=(rstr-1-i)/sub;
        }
    }
    return preans;
}
int main()
{
    gibon
    cin >> stri;
    N=strlen(stri);
    M=min((int)sqrt(N), 300);
    for(int i=N;i>=1;i--)
        stri[i]=stri[i-1];
    idx_one.push_back(0);
    for(int i=1;i<=N;i++)
    {
        pref[i]=pref[i-1];
        if(stri[i]=='1')
        {
            pref[i]++;
            idx_one.push_back(i);
        }
    }
    idx_one.push_back(N+1);
    one=idx_one.size()-2;
    if(one==0)
    {
        cout << 0;
        return 0;
    }
    gasu[N]=1;
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int now=i*pref[j]-j+N;
            total+=gasu[now];
            gasu[now]++;
        }
        for(int j=1;j<=N;j++)
        {
            int now=i*pref[j]-j+N;
            gasu[now]--;
        }
    }
    for(int i=1;i<=N/(M+1);i++)
    {
        for(int j=0;j<=one-i;j++)
        {
            int lstr=idx_one[j], lfin=idx_one[j+1]-1, rstr=idx_one[j+i], rfin=idx_one[j+i+1]-1;
            total+=solve(lstr, lfin, rstr, rfin, i);
        }
    }
    cout << total;
}