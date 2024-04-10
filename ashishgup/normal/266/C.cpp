#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int row[N], col[N];
int actrow[N], actcol[N];
int a[N][N];

int findemptyrow(int i)
{
    for(int j=i;j<=n;j++)
    {
        if(!row[j])
            return j;
    }
    return i;
}  

int findsomecolumn(int i)
{
    for(int j=i;j<=n;j++)
    {
        if(col[j])
            return j;
    }   
    return i;
} 

int swaprow(int x, int y)
{
    for(int i=1;i<=n;i++)
    {
        swap(a[x][i], a[y][i]);
    }
}

int swapcol(int x, int y)
{
    for(int i=1;i<=n;i++)
    {
        swap(a[i][x], a[i][y]);
    }
}

void reducecol(int i)
{
    for(int j=i;j<=n;j++)
    {
        if(a[i][j])
            col[j]--;
    }
}

void reducerow(int i)
{
    for(int j=i+1;j<=n;j++)
    {
        if(a[j][i])
            row[j]--;
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x, y;
        cin>>x>>y;
        row[x]++;
        col[y]++;
        a[x][y]=1;
    }
    actrow[n]=n;
    actcol[n]=n;
    vector<int> ans1;
    vector<pair<int, int> > ans2;
    for(int i=1;i<=n;i++)
    {
        int currow=findemptyrow(i);
        if(currow!=i)
        {
            ans1.push_back(1);
            ans2.push_back({i, currow});
            swap(row[i], row[currow]);
            swaprow(i, currow);
        }
        int curcol=findsomecolumn(i);
        if(curcol!=i)
        {
            ans1.push_back(2);
            ans2.push_back({i, curcol});
            swap(col[i], col[curcol]);
            swapcol(i, curcol);
        }
        reducecol(i);
        reducerow(i);
    }
    cout<<ans1.size()<<endl;
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" "<<ans2[i].first<<" "<<ans2[i].second<<endl;
    }
    return 0;
}