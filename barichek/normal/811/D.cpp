#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

bool swap_1;
bool swap_2;
bool know_swap_1;
bool know_swap_2;

char a[ar][ar];
int n,m;
int x,y;
bool use[ar][ar];

void check()
{
    if (a[x][y]=='F'){
        exit(0);
    }
}

bool ok(int xx,int yy)
{
    return min(xx,yy)>=1&&xx<=n&&yy<=m&&a[xx][yy]!='*';
}

vector<pii> moves={{-1,0},{+1,0},{0,-1},{0,+1}};
char pred[ar][ar];
pii pred1[ar][ar];

void dfs(int num=-1)
{


    use[x][y]=1;
    queue<pii> q;
    q.push(mp(x,y));
    while (!q.empty()){
        int x=q.front().fir;
        int y=q.front().sec;
        q.pop();
        if (a[x][y]=='F'){
            string ans="";
            while (x!=::x||y!=::y){
                ans+=pred[x][y];
                pii dop=pred1[x][y];
                x=dop.fir;
                y=dop.sec;
            }
            reverse(all(ans));
            for (auto i:ans){
                cout<<i<<endl;
                cin>>x>>y;
            }
            exit(0);
        }
        for (int wh=0;wh<4;wh++){
            int to_x=x+moves[wh].fir;
            int to_y=y+moves[wh].sec;
            if (ok(to_x,to_y)){
                if (!use[to_x][to_y]){
                    use[to_x][to_y]=1;
                    pred1[to_x][to_y]=mp(x,y);
                    if (wh==0){
                        q.push(mp(to_x,to_y));
                        pred[to_x][to_y]=char('U'^(('D'^'U')*swap_2));
                    }
                    if (wh==1){
                        q.push(mp(to_x,to_y));
                        pred[to_x][to_y]=char('D'^(('D'^'U')*swap_2));
                    }
                    if (wh==2){
                        q.push(mp(to_x,to_y));
                        pred[to_x][to_y]=char('L'^(('R'^'L')*swap_1));
                    }
                    if (wh==3){
                        q.push(mp(to_x,to_y));
                        pred[to_x][to_y]=char('R'^(('R'^'L')*swap_1));
                    }
                    q.push(mp(to_x,to_y));
                }
            }
        }
    }
    use[x][y]=1;
    check();
    for (int wh=0;wh<4;wh++){
        int to_x=x+moves[wh].fir;
        int to_y=y+moves[wh].sec;
        if (ok(to_x,to_y)){
            if (!use[to_x][to_y]){
                if (wh==0){
                    cout<<char('U'^(('D'^'U')*swap_2))<<endl;
                }
                if (wh==1){
                    cout<<char('D'^(('D'^'U')*swap_2))<<endl;
                }
                if (wh==2){
                    cout<<char('L'^(('R'^'L')*swap_1))<<endl;
                }
                if (wh==3){
                    cout<<char('R'^(('R'^'L')*swap_1))<<endl;
                }
                cin>>x>>y;
                dfs(wh);
            }
        }
    }
    if (num==0){
        cout<<char('D'^(('D'^'U')*swap_2))<<endl;
    }
    if (num==1){
        cout<<char('U'^(('D'^'U')*swap_2))<<endl;
    }
    if (num==2){
        cout<<char('R'^(('R'^'L')*swap_1))<<endl;
    }
    if (num==3){
        cout<<char('L'^(('R'^'L')*swap_1))<<endl;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        //files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if (m>=2&&a[1][2]!='*'){
        cout<<'R'<<endl;
        cin>>x>>y;
        check();
        know_swap_1=1;
        if (x==1&&y==1){
            swap_1=1;
        }
        while (y+1<=m&&a[1][y+1]!='*'){
            cout<<char('R'^(('R'^'L')*swap_1))<<endl;
            cin>>x>>y;
            check();
            if (!know_swap_2&&n>=2&&a[2][y]!='*'){
                cout<<'D'<<endl;
                cin>>x>>y;
                check();
                know_swap_2=1;
                if (x==1){
                    swap_2=1;
                }
                if (!swap_2){
                    cout<<'U'<<endl;
                    cin>>x>>y;
                    check();
                }
            }
        }
        if (!know_swap_2){
            while (y>1){
                cout<<char('L'^(('R'^'L')*swap_1))<<endl;
                cin>>x>>y;
                check();
            }
        }
    }
    if (!know_swap_2&&n>=2&&a[2][1]!='*'){
        cout<<'D'<<endl;
        cin>>x>>y;
        check();
        know_swap_2=1;
        if (x==1&&y==1){
            swap_2=1;
        }
        while (x+1<=n&&a[x+1][1]!='*'){
            cout<<char('D'^(('D'^'U')*swap_2))<<endl;
            cin>>x>>y;
            check();
            if (!know_swap_1&&m>=2&&a[x][2]!='*'){
                cout<<'R'<<endl;
                cin>>x>>y;
                check();
                know_swap_1=1;
                if (y==1){
                    swap_1=1;
                }
                if (!swap_1){
                    cout<<'L'<<endl;
                    cin>>x>>y;
                    check();
                }
            }
        }
    }
    if (!know_swap_1||!know_swap_2){
        return 1;
    }
    dfs();
}