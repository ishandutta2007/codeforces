#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

struct cell {
    int turn, ii, jj, dist;
};

char h[]={'^','>','v','<'};
char l[]={'U','R','D','L'};

inline char mod(char c, int t)
{
    if(c=='+')  return c;
    if(c=='-') {if(t%2==0)return c; else return '|';}
    if(c=='|') {if(t%2==0)return c; else return '-';}
    if(c=='^'||c=='>'||c=='v'||c=='<')
    {
        int r;
        if(c=='^') r=0;
        if(c=='>') r=1;
        if(c=='v') r=2;
        if(c=='<') r=3;
        return h[(r+t)%4];
    }
    int r;
    if(c=='U') r=0;
    if(c=='R') r=1;
    if(c=='D') r=2;
    if(c=='L') r=3;
    return l[(r+t)%4];
}

inline bool can(int a, int b, char o)
{
    if(o=='r')
        return ((a=='+'||a=='-'||a=='>'||a=='U'||a=='L'||a=='D')&&
                (b=='+'||b=='-'||b=='<'||b=='U'||b=='R'||b=='D'));
    if(o=='l')
        return ((a=='+'||a=='-'||a=='<'||a=='U'||a=='R'||a=='D')&&
                (b=='+'||b=='-'||b=='>'||b=='U'||b=='L'||b=='D'));
    if(o=='u')
        return ((a=='+'||a=='|'||a=='^'||a=='L'||a=='R'||a=='D')&&
                (b=='+'||b=='|'||b=='v'||b=='L'||b=='R'||b=='U'));
    if(o=='d')
        return ((a=='+'||a=='|'||a=='v'||a=='L'||a=='R'||a=='U')&&
                (b=='+'||b=='|'||b=='^'||b=='L'||b=='R'||b=='D'));
    return 0;
}

bool vis[1000][1000][4];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
            for(int p=0; p<4; p++)
                vis[i][j][p]=0;
        }
    int ie, je;
    cin>>ie>>je;
    ie--; je--;
    queue<cell> q;
    cell temp;
    temp.ii=ie;
    temp.jj=je;
    temp.turn=0;
    temp.dist=0;
    q.push(temp);
    vis[ie][je][0]=1;
    cin>>ie>>je;
    ie--; je--;
    pii g[]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty())
    {
        cell c=q.front();
        q.pop();
        if(c.ii==ie&&c.jj==je)
        {
            cout<<c.dist;
            return 0;
        }
        c.dist++;
        temp=c;
        temp.turn=(c.turn+1)%4;
        if(vis[c.ii][c.jj][temp.turn]==0)
        {
            vis[c.ii][c.jj][temp.turn]=1;
            q.push(temp);
        }

        for(int i=0; i<4; i++)
        {
            temp=c;
            temp.ii+=g[i].ff;
            temp.jj+=g[i].ss;
            if(temp.ii>=0&&temp.ii<n&&temp.jj>=0&&temp.jj<m&&
               a[temp.ii][temp.jj]!='*'&&!vis[temp.ii][temp.jj][temp.turn])
            {
                char fr=mod(a[c.ii][c.jj],c.turn),
                    to=mod(a[temp.ii][temp.jj],c.turn);
                if(can(fr,to,(temp.ii>c.ii?'d':temp.ii<c.ii?'u':temp.jj>c.jj?'r':'l')))
                {
                    vis[temp.ii][temp.jj][temp.turn]=1;
                    q.push(temp);
                }
            }
        }
    }
    cout<<-1;
    return 0;
}