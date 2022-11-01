#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> c(m+1,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        c[a]++;
    }
    const int inf=(1<<30);
    auto mx=[](int &a,int b){a=max(a,b);};
    vector<vector<int>> now(7,vector<int>(7,-inf));
    now[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        vector<vector<int>> nxt(7,vector<int>(7,-inf));
        for(int a=0;a<=6;a++)
        {
            for(int b=0;b<=6;b++)
            {
                for(int j=0;j<=2;j++)
                {
                    if(a<j||b<j||c[i]<j) continue;
                    mx(nxt[b-j][(c[i]-j)%3],now[a][b]+j+((c[i]-j)/3));
                    if((c[i]-j)>=3) mx(nxt[b-j][((c[i]-j)%3)+3],now[a][b]+j+((c[i]-j)/3)-1);
                    if((c[i]-j)>=6&&(c[i]-j)%3==0) mx(nxt[b-j][6],now[a][b]+j+((c[i]-j)/3)-2);
                }
            }
        }
        for(int a=0;a<=6;a++) for(int b=0;b<=6;b++) mx(nxt[a][b],max(nxt[min(6,a+1)][b],nxt[a][min(6,b+1)]));
        now=nxt;
    }
    int res=0;
    for(int a=0;a<=5;a++) for(int b=0;b<=5;b++) res=max(res,now[a][b]);
    cout << res << "\n";
    return 0;
}