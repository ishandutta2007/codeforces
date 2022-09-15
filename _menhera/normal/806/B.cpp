#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4000;
int N;
int a[5];
int b[5];
int cnt[5];
bool mpavail[4000][5][6]; //i additional submission, prob X can be solvable with point
int calc(int min, int score)
{
    if(min==-1) return 0;
    score = 500*(score+1);
    return score - score / 250 * min;

}
int cscore(int min[], int score[])
{
    int ans = 0;
    for(int i=0; i<5; ++i)
        ans += calc(min[i], score[i]);
    return ans;
}
int helper(int a, int b)
{
    if(a*2>b) return 0;
    if(a*4>b) return 1;
    if(a*8>b) return 2;
    if(a*16>b) return 3;
    if(a*32>b) return 4;
    return 5;
}
int main()
{
    scanf("%d", &N);
    for(int j=0; j<N; ++j)
        for(int i=0; i<5; ++i)
        {
            int t;
            scanf("%d", &t);
            if(t!=-1) cnt[i]++;
            if(j==0) a[i] = t;
            if(j==1) b[i] = t;
        }
    for(int i=0; i<MAXN; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            for(int k=0; k<5; ++k)
            {
                if(j!=0 && a[k]==-1) continue;
                int psc = helper(cnt[k]+j, N+i);
                mpavail[i][k][psc] = true;
            }
        }
    }
    int sc[5];
    int maxv = MAXN;
    for(sc[0]=0; sc[0]<6; sc[0]++)
    for(sc[1]=0; sc[1]<6; sc[1]++)
    for(sc[2]=0; sc[2]<6; sc[2]++)
    for(sc[3]=0; sc[3]<6; sc[3]++)
    for(sc[4]=0; sc[4]<6; sc[4]++)
    {
        int asc = cscore(a, sc);
        int bsc = cscore(b, sc);
        if(asc<=bsc) continue;
        for(int i=0; i<maxv; ++i)
        {
            bool flag = true;
            for(int j=0; j<5; ++j)
                if(!mpavail[i][j][sc[j]])
                    flag = false;           
            if(flag) maxv = i;
        }
    }
    if(maxv==MAXN)
        maxv = -1;
    printf("%d\n", maxv);
}