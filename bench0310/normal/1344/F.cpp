#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    const int N=3001;
    int rows=3*k;
    int cols=2*n+k;
    vector<bitset<N>> b(rows);
    vector in(n,vector(k,bool(0)));
    vector<string> tp(k);
    string colors="RBY";
    auto pos=[&](char c)->int{return colors.find(c);};
    for(int i=0;i<k;i++)
    {
        cin >> tp[i];
        int sz;
        cin >> sz;
        for(int j=0;j<sz;j++)
        {
            int a;
            cin >> a;
            in[a-1][i]=1;
        }
        if(tp[i]=="mix")
        {
            char c;
            cin >> c;
            if(c!='W') b[3*i+pos(c)][cols]=1;
        }
    }
    for(int i=2*n;i<cols;i++) for(int j=0;j<3;j++) b[3*(i-2*n)+j][i]=1;
    for(int i=0;i<n;i++)
    {
        for(char t:{'R','B'})
        {
            char c=t;
            for(int j=0;j<k;j++)
            {
                if(!in[i][j]) continue;
                if(tp[j]=="mix") b[3*j+pos(c)][2*i+(t=='B')]=1;
                else if(tp[j]=="RY"&&(c=='R'||c=='Y')) c^=('R'^'Y');
                else if(tp[j]=="RB"&&(c=='R'||c=='B')) c^=('R'^'B');
                else if(tp[j]=="YB"&&(c=='Y'||c=='B')) c^=('Y'^'B');
            }
        }
    }
    vector<int> where(cols,-1);
    for(int col=0,row=0;col<cols&&row<rows;col++)
    {
        int s=-1;
        for(int i=row;i<rows;i++) if(b[i][col]==1) s=i;
        if(s==-1) continue;
        swap(b[row],b[s]);
        where[col]=row;
        for(int i=0;i<rows;i++) if(b[i][col]==1&&i!=row) b[i]^=b[row];
        row++;
    }
    vector<int> res(cols,0);
    for(int j=0;j<cols;j++) if(where[j]!=-1) res[j]=b[where[j]][cols];
    bool ok=1;
    for(int i=0;i<rows;i++)
    {
        int sum=0;
        for(int j=0;j<cols;j++) sum^=(res[j]*b[i][j]);
        ok&=(sum==b[i][cols]);
    }
    if(ok)
    {
        cout << "YES\n";
        for(int j=0;j<n;j++) cout << ".RBY"[res[2*j]+2*res[2*j+1]];
    }
    else cout << "NO\n";
    return 0;
}