#include <fstream>
#include <queue>

#define M 1010
#define mp make_pair
#define f first
#define s second

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

long n,m,s=0,d,xs[]={1,-1,0,0},ys[]={0,0,1,-1},rat=0,ax[10],ay[10];
bool w[M][M],r[M][M],f[M][M];
queue<pair<long,pair<long,long> > > q;
queue<pair<long,long> > rem[2];

void read(void){
    cin>>n>>m>>d;
    char ch;
    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j){
        cin>>ch;
        r[i][j]=(ch=='R');
        if (ch=='R')
        s++;
        w[i][j]=(ch=='X');
    }

}

bool in(long x, long y){
    return 0<=x && x<n && 0<=y && y<m;
}

void filll(long x, long y, long u){
    long t;
    q.push(mp(0,mp(x,y)));
    while (!q.empty()){
        t=q.front().f;
        x=q.front().s.f;
        y=q.front().s.s;
        if (!f[x][y]){
            if (r[x][y])
            ++rat;
            f[x][y]=1;
            rem[u].push(mp(x,y));
        }
        q.pop();
        if (t<d)
        for (long i=0; i<4; ++i)
        if (in(x+xs[i],y+ys[i]))
        if (!w[x+xs[i]][y+ys[i]])
        q.push(mp(t+1,mp(x+xs[i],y+ys[i])));
    }
}

void removee(long u){
    pair<long,long> p;
    while (!rem[u].empty()){
        p=rem[u].front();
        rem[u].pop();
        f[p.f][p.s]=0;
        if (r[p.f][p.s])
        rat--;
    }
}

void clear(void){
    rat=0;
    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j)
    f[i][j]=0;
}

bool find_and_kill(void){
    long xb,yb;
    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j)
    if (r[i][j] && !f[i][j]){
        xb=i;
        yb=j;
        break;
    }


    for (long i=-d; i<=d; ++i)
    for (long j=-d; j<=d; ++j)
    if (in(xb+i,yb+j))
    if (!w[xb+i][yb+j])
    if (ax[0]!=xb+i || ay[0]!=yb+j){
        filll(xb+i,yb+j,1);
        if (rat==s){
            ax[1]=xb+i;
            ay[1]=yb+j;
            return 1;
        }
        removee(1);
    }
    return 0;
}

bool doit(void){
    long xb,yb;
    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j)
    if (r[i][j]){
        xb=i;
        yb=j;
        break;
    }


    for (long i=-d; i<=d; ++i)
    for (long j=-d; j<=d; ++j)
    if (in(xb+i,yb+j))
    if (!w[xb+i][yb+j]){
        filll(xb+i,yb+j,0);
        if (f[xb][yb]){
            ax[0]=xb+i;
            ay[0]=yb+j;
            if (find_and_kill())
            return 1;
        }
        removee(0);
    }

    return 0;

}


int main()
{
    ios_base::sync_with_stdio(0);
    read();

    if (doit()){
        cout<<ax[0]+1<<" "<<ay[0]+1<<" ";
        cout<<ax[1]+1<<" "<<ay[1]+1<<"\n";
    }
    else
    cout<<"-1\n";

    return 0;
}