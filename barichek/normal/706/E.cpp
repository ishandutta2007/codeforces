#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

pii r[ar][ar],d[ar][ar];
pii r_[ar][ar],d_[ar][ar];
int n,m,mas[ar][ar];

void _debug()
{
    cout<<"debug#\n";
    int x=1,y=1;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
        {
            cout<<i<<" "<<j<<" !!!\n";
            cout<<"right["<<i<<"]["<<j<<"]=={"<<r[i][j].fir<<","<<r[i][j].sec<<"}\n";
            cout<<"down["<<i<<"]["<<j<<"]=={"<<d[i][j].fir<<","<<d[i][j].sec<<"}\n";
        }
    }
}

#define iamdebuger cout<<"now iam in:\n"; cout<<"now_x1=="<<now_x1<<"\n"; cout<<"now_y1=="<<now_y1<<"\n"; cout<<"now_x2=="<<now_x2<<"\n"; cout<<"now_y2=="<<now_y2<<"\n";

int main()
{
    int q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&mas[i][j]);
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++)
            r[i][j]=mp(i,j+1),
            d[i][j]=mp(i+1,j);
    while (q--)
    {
        int x1,y1,x2,y2,h,w;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&h,&w);
        int now_x1=0;
        int now_y1=0;
        for (int i=0;i<x1-1;i++)
        {
            pii dop=d[now_x1][now_y1];
            now_x1=dop.fir;
            now_y1=dop.sec;
        }
        for (int i=0;i<y1-1;i++)
        {
            pii dop=r[now_x1][now_y1];
            now_x1=dop.fir;
            now_y1=dop.sec;
        }
        pii dop1=mp(now_x1,now_y1);
        int now_x2=0;
        int now_y2=0;
        for (int i=0;i<x2-1;i++)
        {
            pii dop=d[now_x2][now_y2];
            now_x2=dop.fir;
            now_y2=dop.sec;
        }
        for (int i=0;i<y2-1;i++)
        {
            pii dop=r[now_x2][now_y2];
            now_x2=dop.fir;
            now_y2=dop.sec;
        }
        pii dop2=mp(now_x2,now_y2);

        //for (int i=0;i<ar;i++)
          //  for (int j=0;j<ar;j++)
            //    d_[i][j]=d[i][j],
              //  r_[i][j]=r[i][j];

        for (int i=0;i<w;i++)
        {
            //iamdebuger
            pii dop1_=r[now_x1][now_y1];
            pii dop2_=r[now_x2][now_y2];
            now_x1=dop1_.fir;
            now_y1=dop1_.sec;
            now_x2=dop2_.fir;
            now_y2=dop2_.sec;
            swap(d[now_x1][now_y1],d[now_x2][now_y2]);
        }
        for (int i=0;i<h;i++)
        {
            //iamdebuger
            pii dop1_=d[now_x1][now_y1];
            pii dop2_=d[now_x2][now_y2];
            now_x1=dop1_.fir;
            now_y1=dop1_.sec;
            now_x2=dop2_.fir;
            now_y2=dop2_.sec;
            swap(r[now_x1][now_y1],r[now_x2][now_y2]);
        }

        now_x1=dop1.fir;
        now_y1=dop1.sec;
        now_x2=dop2.fir;
        now_y2=dop2.sec;

        //cout<<"tuiky nu\n";

        for (int i=0;i<h;i++)
        {
            //iamdebuger
            pii dop1_=d[now_x1][now_y1];
            pii dop2_=d[now_x2][now_y2];
            now_x1=dop1_.fir;
            now_y1=dop1_.sec;
            now_x2=dop2_.fir;
            now_y2=dop2_.sec;
            swap(r[now_x1][now_y1],r[now_x2][now_y2]);
        }
        for (int i=0;i<w;i++)
        {
            //iamdebuger
            pii dop1_=r[now_x1][now_y1];
            pii dop2_=r[now_x2][now_y2];
            now_x1=dop1_.fir;
            now_y1=dop1_.sec;
            now_x2=dop2_.fir;
            now_y2=dop2_.sec;
            swap(d[now_x1][now_y1],d[now_x2][now_y2]);
        }
        //_debug();
    }
    int x=d[0][1].fir;
    int y=d[0][1].sec;
    for (int i=0;i<n;i++)
    {
        pii start=mp(x,y);
        for (int j=0;j<m;j++)
        {
            cout<<mas[x][y]<<" ";
            int x_=x,y_=y;
            x=r[x_][y_].fir;
            y=r[x_][y_].sec;
        }
        cout<<"\n";
        x=d[start.fir][start.sec].fir;
        y=d[start.fir][start.sec].sec;
    }
}